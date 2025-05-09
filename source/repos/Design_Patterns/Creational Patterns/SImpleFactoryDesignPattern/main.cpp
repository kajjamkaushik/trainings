#include "logger_factory.hpp"
int main()
{
	ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::DEBUG);
	ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);
	ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);

	debugLogger->log("This is debug log msg");
	errorLogger->log("this is error log msg ");
	infoLogger->log("This is info log msg");

	// delete these objects created using new to avoid memory Leaks
	delete debugLogger;
	delete errorLogger;
	delete infoLogger;

	return 0;
}
//output :
//DEBUG: This is debug log msg
//ERROR : this is error log msg
//INFO : This is info log msg