// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

//#include "easylogging++.h"

#include "ExampleService.h"
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/THttpServer.h>

#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class ExampleServiceHandler : virtual public ExampleServiceIf {
 public:
  ExampleServiceHandler() {
    // Your initialization goes here
    printf("Initializing service handler");
  }

  int32_t setExampleStruct(const  ::ExampleStruct& t) {
    // Your implementation goes here
    printf("setExampleStruct\n");
    value = t;
    return 0;
  }

  void getExampleStruct( ::ExampleStruct& _return) {
    // Your implementation goes here
    printf("getExampleStruct\n");
    _return = value;
  }

 private:
  ::ExampleStruct value;

};

/*
#define LOGGING_CONFIG "configs/general.conf"
#define LOGGING_LVL_CONFIG "configs/level.conf"
*/
void initializeLogging(int argc, char **argv) {
    /*
    START_EASYLOGGINGPP(argc, argv);
    el::Configurations conf(LOGGING_CONFIG);
    el::Loggers::reconfigureAllLoggers(conf);
    el::Loggers::configureFromGlobal(LOGGING_LVL_CONFIG);
    */
}

int main(int argc, char **argv) {
  /*
  initializeLogging(argc, argv);
  CLOG(DEBUG, "main") << "Starting up server";
  */
  int port = 9090;
  shared_ptr<ExampleServiceHandler> handler(new ExampleServiceHandler());
  shared_ptr<TProcessor> processor(new ExampleServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

