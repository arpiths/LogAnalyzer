#pragma once

#include <string>

enum class Severity{
    INFO,
    WARNING,
    ERROR,
    FATAL,
    UNKNOWN
};

struct LogEvent {
    std::string timestamp;
    Severity severity;
    std::string message;
};