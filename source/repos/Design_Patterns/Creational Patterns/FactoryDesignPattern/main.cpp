#include "debug_logger_factory.hpp"
#include "error_logger_factory.hpp"
#include "info_logger_factory.hpp"

int main()
{
	ILoggerFactory* loggerFactory1 = new InfoLoggerFactory;
	ILogger* infoLogger = loggerFactory1->createLogger();
	
	ILoggerFactory* loggerFactory2 = new DebugLoggerFactory;
	ILogger* debugLogger = loggerFactory2->createLogger();

	ILoggerFactory* loggerFactory3 = new ErrorLoggerFactory;
	ILogger* errorLogger = loggerFactory3->createLogger();

	infoLogger->log("This is a debug log msg ");
	debugLogger->log("This is a debug log msg ");
	errorLogger->log("This is a debug log msg ");

	delete infoLogger;
	delete debugLogger;
	delete errorLogger;
	return 0;
}

//output:
//INFO: This is a debug log msg
//DEBUG : This is a debug log msg
//ERROR : This is a debug log msg