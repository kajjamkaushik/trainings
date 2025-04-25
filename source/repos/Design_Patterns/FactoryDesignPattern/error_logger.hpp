#pragma once
#include "ilogger.hpp"
class ErrorLogger :public ILogger
{
	void log(const string& msg);
};