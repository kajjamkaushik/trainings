#include "logger_factory.hpp"

ILogger* LoggerFactory::createLogger(LogLevel pLogLevel)
{
	if (pLogLevel == LogLevel::DEBUG)
		return new DebugLogger;
	if (pLogLevel == LogLevel::ERROR)
		return new ErrorLogger;
	if (pLogLevel == LogLevel::INFO)
		return new InfoLogger;
	return nullptr;
}