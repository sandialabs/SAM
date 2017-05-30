#define BOOST_TEST_MAIN TestBaseComputation
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <vector>
#include <string>
#include "BaseComputation.hpp"
#include "Netflow.hpp"
#include "Util.hpp"

using namespace sam;


BOOST_AUTO_TEST_CASE( test_generate_key )
{
  std::string netflowString1 = "1365582756.384094,2013-04-10 08:32:36," 
                         "20130410083236.384094,17,UDP,172.20.2.18," 
                         "239.255.255.250,29986,1900,0,0,0,133,0,1,0,1,0,0";
  size_t valueField = SRC_PAYLOAD_BYTES;
  FeatureMap featureMap;
  size_t nodeId = 0;
  std::string id = "blah";
  BaseComputation computation(nodeId, featureMap, id);
                                                               
                                                               

  Netflow netflow = makeNetflow(netflowString1);
  std::string key = generateKey<SOURCE_IP_FIELD>(netflow);

  BOOST_CHECK_EQUAL(key.compare("172.20.2.18"), 0);
}
