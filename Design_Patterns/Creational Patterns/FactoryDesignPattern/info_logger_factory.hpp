#pragma once
#include "logger_factory.hpp"
#include "info_logger.hpp"

class InfoLoggerFactory : public ILoggerFactory {
public:
    ILogger* createLogger () override {
        return new InfoLogger();
    }
};
