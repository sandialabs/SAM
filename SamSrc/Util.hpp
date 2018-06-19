#ifndef SAM_UTIL_HPP
#define SAM_UTIL_HPP

#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <numeric>
#include <iostream>
#include <queue>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <zmq.hpp>
#include <mutex>
#include <list>
#include <memory>
#include <thread>
#include <atomic>


namespace sam {


#ifdef DETAIL_TIMING
  #define DETAIL_TIMING_BEG1 \
  auto detailTimingBegin = std::chrono::high_resolution_clock::now();
  
  #define DETAIL_TIMING_BEG2 \
  detailTimingBegin = std::chrono::high_resolution_clock::now();

  #define DETAIL_TIMING_END1(var) \
  auto detailTimingEnd = std::chrono::high_resolution_clock::now();\
  auto detailTimingDiff = \
    std::chrono::duration_cast<std::chrono::duration<double>>(\
      detailTimingEnd - detailTimingBegin);\
  var += detailTimingDiff.count();

  #define DETAIL_TIMING_END_TOL1(nodeId, var, tolerance, message) \
  auto detailTimingEnd = std::chrono::high_resolution_clock::now();\
  auto detailTimingDiff = \
    std::chrono::duration_cast<std::chrono::duration<double>>(\
      detailTimingEnd - detailTimingBegin);\
  double localDiff = detailTimingDiff.count(); \
  if (localDiff > tolerance) { \
    printf("Node %lu Time tolerance exceeded: %f %s\n", nodeId, localDiff,\
            message); \
  }\
  var += detailTimingDiff.count();


  #define DETAIL_TIMING_END2(var) \
  detailTimingEnd = std::chrono::high_resolution_clock::now();\
  detailTimingDiff = std::chrono::duration_cast<std::chrono::duration<double>>(\
    detailTimingEnd - detailTimingBegin);\
  var += detailTimingDiff.count();

  #define DETAIL_TIMING_END_TOL2(nodeId, var, tolerance, message)\
  detailTimingEnd = std::chrono::high_resolution_clock::now();\
  detailTimingDiff = \
    std::chrono::duration_cast<std::chrono::duration<double>>(\
      detailTimingEnd - detailTimingBegin);\
  localDiff = detailTimingDiff.count(); \
  if (localDiff > tolerance) { \
    printf("Node %lu Time tolerance exceeded: %f %s\n", nodeId, localDiff,\
            message); \
  }\
  var += detailTimingDiff.count();

#else
  #define DETAIL_TIMING_BEG1
  #define DETAIL_TIMING_BEG2
  #define DETAIL_TIMING_END1(var)
  #define DETAIL_TIMING_END2(var)
  #define DETAIL_TIMING_END_TOL1(nodeId, var, tolerance, message)
  #define DETAIL_TIMING_END_TOL2(nodeId, var, tolerance, message)
#endif

#ifdef METRICS
  #define METRICS_INCREMENT(var) var++;
#else
  #define METRICS_INCREMENT(var) 
#endif

#ifdef DEBUG
  #define DEBUG_PRINT(message, ...) printf(message, __VA_ARGS__);
#else
  #define DEBUG_PRINT(message, ...) 
#endif


class UtilException : public std::runtime_error {
public:
  UtilException(char const * message) : std::runtime_error(message) { } 
  UtilException(std::string message) : std::runtime_error(message) { } 
};



/**
 * Generates a subtuple based on the provided index_sequence.
 */
template <typename... T, std::size_t... I>
auto subtuple(std::tuple<T...> const& t, std::index_sequence<I...>) {
  return std::make_tuple(std::get<I>(t)...);
}

/**
 * Base cae for generateKey.
 */
template <typename...  Ts>
std::string generateKey(std::tuple<Ts...> const& t)
{
  return "";
}

/**
 * Generates a key based on the keyfields provided to the template.
 */
template <size_t keyField, size_t... keyFields, typename... Ts>
std::string generateKey(std::tuple<Ts...> const& t)
{
  std::string key = boost::lexical_cast<std::string>(std::get<keyField>(t));
  return key + generateKey<keyFields...>(t);
}


/**
 * Base case for tupleToString
 */
template <int I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), std::string>::type
tupleToString(std::tuple<Tp...> const&)
{
  return "";
}

/**
 * Generates a string from the tuple.
 */
template<int I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), std::string>::type
tupleToString(std::tuple<Tp...>const& t)
{
  std::string result = boost::lexical_cast<std::string>(std::get<I>(t));
  result = result + "," + tupleToString<I + 1, Tp...>(t);
  if (result[result.size() - 1] == ',') {
    result = result.substr(0, result.size()-1);
  }
  return result;
}

template<typename... Tp>
std::string toString(std::tuple<Tp...>const& t) {
  std::string result = tupleToString(t);
  return result;
}

/**
 * Hash function for strings.
 */
inline
uint64_t hashFunction(std::string const& key) 
{
  uint64_t hash = 0;
  
  for (int i = 0; i < key.size(); i++) {
    hash = key[i] + (hash << 6) + (hash << 16) - hash;
  }

  return hash;
}

class StringHashFunction
{
public:
  inline
  uint64_t operator()(std::string const& s) const {
    return std::hash<std::string>{}(s);
    //return hashFunction(s);
  }
};

/**
 * This is used for testing purposes.  It assumes the strings are ip4 addresses.
 * It just looks at the last octet and returns that.  This is useful so that
 * we can create testing situations where we know where ip addresses will
 * go by design, rather than randomly.
 */
class LastOctetHashFunction
{
public:
  inline
  uint64_t operator()(std::string const& s) const {
    size_t index = s.find_last_of(".");
    std::string lastOctet = s.substr(index + 1);
    return boost::lexical_cast<uint64_t>(lastOctet);
  }
};

class TimeConversionFunction
{
public:
  inline
  uint64_t operator()(double time) const {
    return static_cast<uint64_t>(time * 10000000);
  }
};

class StringEqualityFunction
{
public:
  inline
  bool operator()(std::string const& s1, std::string const& s2) const
  {
    return s1.compare(s2) == 0;
  }
};

template <typename T>
double calcMean(T const& v)
{
  double sum = std::accumulate(v.begin(), v.end(), 0.0);
  return sum / v.size();
}

//template <typename T>
//double calcMean(std::deque<T> const& v)
//{
//  double sum = std::accumulate(v.begin(), v.end(), 0.0);
//  return sum / v.size();
//}

template <typename T>
double calcStandardDeviation(T const& v)
{
  double mean = calcMean(v);

  std::vector<double> diff(v.size());
  std::transform(v.begin(), v.end(), diff.begin(), 
    [mean](double x) { return x - mean; });
  double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 
                                     0.0);
  return std::sqrt(sq_sum / v.size());
}

/**
 * Converts a netflow string into a vetor of tokens.
 */
inline
std::vector<std::string> convertToTokens(std::string netflowString) {
  boost::char_separator<char> sep(",");
  boost::tokenizer<boost::char_separator<char>> tokenizer(netflowString, sep);
  std::vector<std::string> v;
  for ( std::string t : tokenizer ) {
    v.push_back(t);
  }
  return v;
}


std::string getIpString(std::string hostname) {
  hostent* hostInfo = gethostbyname(hostname.c_str());
  in_addr* address = (in_addr*)hostInfo->h_addr;
  std::string ip = inet_ntoa(* address);
  return ip;
}

/**
 * Given a string, creates a zmq message with the string as the data.
 * \param str The string that is to be the data of the message.
 * \return Returns a zmq::message_t with the string as the data.
 */
zmq::message_t fillZmqMessage(std::string const& str)
{
  zmq::message_t message(str.length());
  char* dataptr = (char*) message.data();
  std::copy(str.begin(), str.end(), dataptr);
  return message;
}

/**
 * Given the zmq message, extract the data as a string.
 * \param message The zmq to get the data from.
 * \return Returns the zmq data as a string.
 */
std::string getStringFromZmqMessage( zmq::message_t const& message )
{
  // Reinterpret the void pointer to be an unsigned char pointer.
  unsigned char const * dataptr = 
    reinterpret_cast<unsigned char const*>(message.data());

  // Creates a string with proper size so we can iterate over it and 
  // copy in the values from the message.
  std::string rString(message.size(), 'x');

  std::copy(dataptr, &dataptr[message.size()], rString.begin());
  return rString;
}

template<typename... Tp>
inline zmq::message_t tupleToZmq(std::tuple<Tp...>const& t)
{
  std::string str = toString(t);
  zmq::message_t message = fillZmqMessage(str);

  return message;
}

/**
 * Creates an empty zmq message.  We use this to indicate a terminate
 * message.
 */
zmq::message_t emptyZmqMessage() {
  std::string str = "";
  zmq::message_t message = fillZmqMessage(str);
  return message;
}

/**
 * Creates a zmq message that means terimate
 */
zmq::message_t terminateZmqMessage() {
  return emptyZmqMessage();
  //std::string str = "terminate";
  //zmq::message_t message = fillZmqMessage(str);
  //return message;
}



/**
 * Checks if the zmq message is a terminate message. A terminate message
 * is one with an empty string.
 */
bool isTerminateMessage(zmq::message_t& message)
{
  //std::string str = getStringFromZmqMessage(message);
  //if (str.compare("terminate") == 0) {
  //  return true;
  //}
  //return false;
  if (message.size() == 0) return true;
  return false;
}

inline
size_t get_begin_index(size_t num_elements, size_t stream_id, 
                       size_t num_streams)
{
  return static_cast<size_t>((static_cast<double>(num_elements) / num_streams) *
                        stream_id);
}

inline
size_t get_end_index(size_t num_elements, size_t stream_id, 
                       size_t num_streams)
{

  return (stream_id + 1 < num_streams) ?
    static_cast<size_t>((static_cast<double>(num_elements) / num_streams) *
                       (stream_id + 1)) :
    num_elements;
 
}

inline
void
createPushSockets(
    zmq::context_t* context,
    size_t numNodes,
    size_t nodeId,
    std::vector<std::string>& hostnames,
    std::vector<size_t>& ports,
    std::vector<std::shared_ptr<zmq::socket_t>>& pushers,
    uint32_t hwm)
{
  pushers.resize(numNodes);
  for (int i = 0; i < numNodes; i++) 
  {
    if (i != nodeId) // never need to send stuff to itself
    {
      //printf("createpushsockets nodeId %lu %d\n", nodeId, i);
      /////////// adding push sockets //////////////
      auto pusher = std::shared_ptr<zmq::socket_t>(
                      new zmq::socket_t(*context, ZMQ_PUSH));
      //printf("createpushsockets nodeId %lu %d created socket\n", 
      //        nodeId, i);

      std::string ip = getIpString(hostnames[nodeId]);
      std::string url = "";
      url = "tcp://" + ip + ":";
      try { 
        url = url + boost::lexical_cast<std::string>(ports[i]);
      } catch (std::exception e) {
        throw UtilException(e.what());
      }

      // the function complains if you use std::size_t, so be sure to use the
      // uint32_t class member for hwm.
      try {
        pusher->setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
      } catch (std::exception e) {
        std::string message = std::string("problem setting push socket's send")+
          std::string(" high water mark: ") + e.what();
        throw UtilException(message);
      }
      //printf("createpushsockets url %s nodeId %lu %d set socket option\n", 
      //    url.c_str(), nodeId, i);
      //pusher->connect(url);
      try {
        #ifdef DEBUG
        printf("Node %lu createPushSockets binding to %s\n", nodeId, 
          url.c_str());
        #endif
        pusher->bind(url);
      } catch (std::exception e) {
        std::string message = "Node " +
          boost::lexical_cast<std::string>(nodeId) +
          " couldn't bind to url " + url + ": " + e.what();
        throw UtilException(message);
      }
      pushers[i] = pusher;
    } 
  }
}

namespace numTrianglesDetails
{

/// Struct for holding the intermediate results.
template<typename TupleType, size_t source, size_t target, size_t time,
         size_t duration>
struct PartialTriangle {
  size_t numEdges = 0;
  TupleType netflow1;
  TupleType netflow2;

  std::string toString() const {
    std::string rString = "numEdges " + 
      boost::lexical_cast<std::string>(numEdges) + " ";
    if (numEdges > 0) {
      rString += sam::toString(netflow1) + " ";
    } 
    if (numEdges > 1) {
      rString += sam::toString(netflow2);
    }
    return rString;
  }

  /**
   * Determines if the intermediate result is expired by looking at the 
   * provided current time and seeing if we are still in the allowed
   * time window.
   */
  bool isExpired(double currentTime, double timeWindow) {
    double startTime = std::get<time>(netflow1);
    DEBUG_PRINT("isExpired startTime %f currentTime %f currentTime -"
           " startTime %f timeWindow %f comparison %f\n",
      startTime, currentTime, currentTime - startTime, timeWindow,
      currentTime - startTime - timeWindow);
    if (currentTime - startTime <= timeWindow) {
      return false;
    }
    return true;
  }

  /*size_t operator()(PartialTriangle const& partial) const 
  {
    if (partial.numEdges == 1) {
      auto trg = std::get<target>(partial.netflow1);
      return hashFunction(trg);        
    }
    if (partial.numEdges == 2) {
      auto trg = std::get<target>(partial.netflow2);
      return hashFunction(trg);        
    }
    throw UtilException("Tried to hash a partial triangle but the"
      " number of edges was not 1 or 2."); 
  }

  bool operator==(PartialTriangle const& other) const
  {
    if (numEdges != other.numEdges) {
      return false;
    }
    if (numEdges >= 1) {
      std::string s1 = toString(netflow1);
      std::string s2 = toString(other.netflow1);
      if (s1.compare(s2) != 0) {
        return false;
      } 
    }

    if (numEdges == 2) {
      std::string s1 = toString(netflow2);
      std::string s2 = toString(other.netflow2);
      if (s1.compare(s2) != 0) {
        return false;
      } 
    }

    return true;
  }*/

};

} //End numTrianglesDetails

/**
 * This is an alternate method for calculating triangles.  It is used to 
 * validate the parallel framework to make sure they get the same answer.
 * This checks that all the edges have strictly increasing times
 * and that all the edges occur within the specified time frame.
 * \param l, a vector of tuples.
 * \param queryTime, the length of the query
 */
template<typename TupleType, size_t source, size_t target, size_t time,
         size_t duration>
size_t numTriangles(std::vector<TupleType> l, double queryTime)
{
  using namespace sam::numTrianglesDetails;
  
  typedef PartialTriangle<TupleType, source, target, time, duration>
    PartialTriangleType;

  typedef typename std::tuple_element<source, TupleType>::type SourceType;
  typedef typename std::tuple_element<target, TupleType>::type TargetType;

  // TODO: parallelize sort
  #ifdef DETAIL_TIMING
  double totalTimeSort = 0;
  #endif
  DETAIL_TIMING_BEG1
  std::sort(l.begin(), l.end(), [](TupleType const& t1, 
                                   TupleType const& t2) ->bool
  {
    return std::get<time>(t1) < std::get<time>(t2);  
  });
  DETAIL_TIMING_END1(totalTimeSort);
  #ifdef DETAIL_TIMING
  printf("numTriangles time to sort %f\n", totalTimeSort);
  #endif

  // Set the id to be the sort order.
  for (size_t i = 0; i < l.size(); i++) {
    std::get<0>(l[i]) = i;
  }

  //std::map<

  std::vector<PartialTriangleType> partialTriangles;

  std::atomic<size_t> numTriangles(0);

  size_t numThreads = std::thread::hardware_concurrency();
  //size_t numThreads = 1;
  printf("numTriangles numThreads %lu\n", numThreads); 

  for (auto tuple : l) 
  {
    double currentTime = std::get<time>(tuple);

    DEBUG_PRINT("Beginning processing Tuple %s\n", 
      sam::toString(tuple).c_str());
    PartialTriangleType p;
    p.numEdges = 1;
    p.netflow1 = tuple;
   

    // New partial triangles that arise from processing this tuple
    // are added to this data structure (in parallel), and then
    // added back into partialTriangles after the parallel processing.
    std::vector<PartialTriangleType> newPartials;

    std::vector<std::thread> threads;
    threads.resize(numThreads);

    // Lock used to add things to newPartials in a thread-safe way.
    std::mutex lock;
  
    for (size_t t = 0; t < numThreads; t++)  
    {
      threads[t] = std::thread([&partialTriangles, &newPartials, t,
       numThreads, tuple, queryTime, &lock, &numTriangles,
       currentTime  ]() 
      {

        size_t beg = get_begin_index(partialTriangles.size(), t, numThreads); 
        size_t end = get_end_index(partialTriangles.size(), t, numThreads);
        for (size_t i = beg; i < end; i++) 
        {
          auto partial = partialTriangles[i];
           
          // Determine if the partial is expired 
          if (!partial.isExpired(currentTime, queryTime))
          {
            lock.lock();
            newPartials.push_back(partial);
            lock.unlock();
            if (partial.numEdges == 1) {
              auto id1 = std::get<0>(partial.netflow1);
              auto id2 = std::get<0>(tuple);
              if (id1 != id2) {

                auto trg1 = std::get<target>(partial.netflow1);
                auto src2 = std::get<source>(tuple);
                if (trg1 == src2) 
                {
                  double t1 = std::get<time>(partial.netflow1);
                  double t2 = std::get<time>(tuple);

                  // Inforces strictly increasing times
                  if (t1 < t2) 
                  {
                    double dur = std::get<duration>(tuple);
                    if (t2 + dur - t1 < queryTime) {
                      PartialTriangleType newPartial;
                      newPartial.numEdges = 2;
                      newPartial.netflow1 = partial.netflow1;
                      newPartial.netflow2 = tuple;  

                      DEBUG_PRINT("newpartial %f %s %s, "
                         " %f %s %s\n",
                         std::get<time>(newPartial.netflow1),
                         std::get<source>(newPartial.netflow1).c_str(),
                         std::get<target>(newPartial.netflow1).c_str(),
                         std::get<time>(newPartial.netflow2),
                         std::get<source>(newPartial.netflow2).c_str(),
                         std::get<target>(newPartial.netflow2).c_str());

                      lock.lock();
                      newPartials.push_back(newPartial);
                      lock.unlock();
                    }
                  }
                }
              }
            }
            else if (partial.numEdges == 2) {
              auto id1 = std::get<0>(partial.netflow1);
              auto id2 = std::get<0>(partial.netflow2);
              auto id3 = std::get<0>(tuple);

              DEBUG_PRINT("tuple %s id1 %lu id2 %lu id3 %lu\n", 
                toString(tuple).c_str(), id1, id2, id3);

              if (id1 != id3 && id2 != id3) {
                DEBUG_PRINT("tuple %s, id1!=id3 id2 != id3\n", 
                  toString(tuple).c_str());
                auto trg2 = std::get<target>(partial.netflow2);
                auto src3 = std::get<source>(tuple);
                DEBUG_PRINT("tuple %s trg2 %s src3 %s\n",
                  toString(tuple).c_str(), trg2.c_str(), src3.c_str()); 
                if (trg2 == src3) {
                  DEBUG_PRINT("tuple %s trg2 == src3\n", 
                    toString(tuple).c_str());
                  auto trg3 = std::get<target>(tuple) ;
                  auto src1 = std::get<source>(partial.netflow1);
                  if (trg3 == src1) {
                    DEBUG_PRINT("tuple %s trg3 %s src1 %s\n", 
                      toString(tuple).c_str(), trg3.c_str(), src1.c_str()); 
                    double t1 = std::get<time>(partial.netflow1);
                    double t2 = std::get<time>(partial.netflow2);
                    double t3 = std::get<time>(tuple);
                    double dur = std::get<duration>(tuple);

                    // Inforces strictly increasing times
                    DEBUG_PRINT("tuple %s t3 %f t2 %f t1 %f dur %f queryTime %f"
                      "\n", toString(tuple).c_str(), t3, t2, t1, dur, 
                      queryTime);
                    if (t3 > t2 && t3 + dur -t1 <= queryTime) {

                      DEBUG_PRINT("found triangle edge1 %lu %f %s %s, "
                        "edge2 %lu %f %s %s, "
                        "edge3 %lu %f %s %s\n",
                        std::get<0>(partial.netflow1),
                        std::get<time>(partial.netflow1),
                        std::get<source>(partial.netflow1).c_str(),
                        std::get<target>(partial.netflow1).c_str(),
                        std::get<0>(partial.netflow2),
                        std::get<time>(partial.netflow2),
                        std::get<source>(partial.netflow2).c_str(),
                        std::get<target>(partial.netflow2).c_str(),
                        std::get<0>(tuple),
                        std::get<time>(tuple),
                        std::get<source>(tuple).c_str(),
                        std::get<target>(tuple).c_str());

                      numTriangles.fetch_add(1);
                    }
                  }
                }
              }
            }
          } else {
            DEBUG_PRINT("tuple %s partial expired %s\n", 
              toString(tuple).c_str(), partial.toString().c_str());
          }
        }
      });
    }
    for(size_t i = 0; i < numThreads; i++) {
      threads[i].join();
    }

    // A single edge is a partial triangle 
    newPartials.push_back(p);
    DEBUG_PRINT("tuple %s num new partials %lu\n", toString(tuple).c_str(),
      newPartials.size());

    partialTriangles.clear();
    if (partialTriangles.capacity() < newPartials.size()) 
    {
      partialTriangles.resize(newPartials.size());
    }

    for (size_t t = 0; t < numThreads; t++)  
    {
      threads[t] = std::thread([&partialTriangles, &newPartials, t,
       numThreads, tuple, queryTime, &lock, &numTriangles  ]() 
      {

        size_t beg = get_begin_index(newPartials.size(), t, numThreads); 
        size_t end = get_end_index(newPartials.size(), t, numThreads);

        for (size_t i = beg; i < end; i++) {
          partialTriangles[i] = newPartials[i];
        }
      }
      );
    }

    for(size_t i = 0; i < numThreads; i++) {
      threads[i].join();
    }
  }

  return numTriangles;
}
  


}

#endif
