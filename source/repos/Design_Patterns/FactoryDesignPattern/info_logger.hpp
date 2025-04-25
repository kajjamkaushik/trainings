#pragma once
#include "ilogger.hpp"

class InfoLogger :public ILogger
{
	void log(const string& msg);
};