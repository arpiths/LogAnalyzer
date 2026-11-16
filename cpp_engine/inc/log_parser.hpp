#pragma once

#include "log_event.hpp"
#include <vector>
#include <string>

using namespace std;

class LogParser {
    public:
        vector<LogEvent> parseFile(const string& logFilePath);
        int getCountMalformed() const;

    private:
        Severity parseSeverity(const string& severity);
        int CountMalformed = 0;


};
