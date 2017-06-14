#include <iostream>
#include "flv/flv_parser.h"
#include "xutil/easylogging++.h"
INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
    START_EASYLOGGINGPP(argc, argv);
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
                                       "%datetime %func[%fbase] %level: %msg");
	flv::FLVParser* parser = new flv::FLVParser;
	std::string file(argv[1]);
	int rc = parser->set_file(file);
	delete parser;
	return rc;
}
