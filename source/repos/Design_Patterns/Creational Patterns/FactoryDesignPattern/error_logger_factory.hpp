#pragma once
#include "logger_factory.hpp"
#include "error_logger.hpp"

class ErrorLoggerFactory :public ILoggerFactory
{
public:
	ILogger* createLogger () override{
		return new ErrorLogger();
	}
};