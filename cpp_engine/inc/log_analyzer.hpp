
#pragma once

#include "log_event.hpp"

#include <vector>
#include <map>
#include <string>

using namespace std;

class LogAnalyzer {

    public:

        void analyze( const vector<LogEvent>& events);

        vector<LogEvent> getErrors(const vector<LogEvent>& events);
        const std::map<std::string, int>& getSeverityCounts() const;
    
    private:

        map<string, int> severityCounts;

};
