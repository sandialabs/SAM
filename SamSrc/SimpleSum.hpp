#ifndef SIMPLE_SUM_HPP
#define SIMPLE_SUM_HPP

/**
 * This is a simple implementation of sum that is not space efficient
 * (i.e. O(N) where N is the size of the sliding window).
 */

#include <iostream>
#include <map>
#include <boost/lexical_cast.hpp>
#include "AbstractConsumer.hpp"
#include "BaseComputation.hpp"
#include "Features.hpp"

namespace sam 
{

namespace SimpleSumDetails {

template <typename T>
class SimpleSumDataStructure {
private:
  size_t N;
  T* array;
  T sum;
  int current = 0;

public:
  SimpleSumDataStructure(size_t N) {
    this->N = N;
    array = new T[N]();
    for (int i = 0; i < N; i++) array[i] = 0;
    sum = 0;
  }

  ~SimpleSumDataStructure() {
    delete[] array;
  }

  /**
   * Adds an item, removing an item if needbe, and
   * updating the sum.
   */
  void insert(T item) {
    sum = sum - array[current];
    array[current] = item;
    current++;
    if (current >= N) {
      current = 0;
    }
    sum = sum + item;
  }

  T getSum() {
    return sum;
  }
};

}


template <typename T, typename TupleType>
class SimpleSum: public AbstractConsumer<TupleType>, public BaseComputation 
{
private:
  size_t N; ///> Size of sliding window
  typedef SimpleSumDetails::SimpleSumDataStructure<T> value_t;

  /// Mapping from the key (e.g. an ip field) to the simple sum 
  /// data structure that is keeping track of the values seen.
  std::map<string, value_t*> allWindows; 
  
  // Where the most recent item is located in the array.
  size_t top = 0;
  
public:
  SimpleSum(size_t N,
            std::vector<size_t> keyFields,
            size_t valueField,
            size_t nodeId,
            FeatureMap& featureMap,
            string identifier) :
    BaseComputation(keyFields, valueField, nodeId, featureMap, identifier) 
  {
    this->N = N;
  }

  ~SimpleSum()   {
    for (auto p : allWindows) {
      delete p.second;
    }
  }

  bool consume(TupleType const& tuple) {
    this->feedCount++;
    if (this->feedCount % metricInterval == 0) {
      std::cout << "SimpleSum: NodeId " << nodeId << " feedCount " 
                << this->feedCount << std::endl;
    }

    // Generates unique key from key fields 
    string key = generateKey(tuple);
    if (allWindows.count(key) == 0) {
      auto value = new value_t(N); 
      allWindows[key] = value;
    }

    string sValue = tuple.getField(valueField);
    T value;
    try {
      value = boost::lexical_cast<T>(sValue);
    } catch (std::exception e) {
      std::cerr << "SimpleSum::consume Caught exception trying to cast string "
                << "value of " << sValue << std::endl;
      std::cerr << e.what() << std::endl;
      value = 0;
    }

    allWindows[key]->insert(value);
    
    // Getting the current sum and providing that to the imux data structure.
    T currentSum = allWindows[key]->getSum();
    SingleFeature feature(currentSum);
    featureMap.updateInsert(key, identifier, feature);

    return true;
  }

  T getSum(string key) {
    return allWindows[key]->getSum();
  }

  std::vector<string> keys() const {
    std::vector<string> theKeys;
    for (auto p : allWindows) {
      theKeys.push_back(p.first);
    }
    return theKeys;
  }

};

}


#endif
