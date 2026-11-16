#include "log_parser.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;


Severity LogParser::parseSeverity(const string& severity){
            if (severity == "INFO") {
                return Severity::INFO;
            } else if (severity == "WARNING") {
                return Severity::WARNING;
            } else if (severity == "ERROR") {
                return Severity::ERROR;
            } else if (severity == "FATAL") {
                return Severity::FATAL;
            } 
                return Severity::UNKNOWN;
            
        }


vector<LogEvent> LogParser::parseFile(const string& logFilePath){
    fstream logfile(logFilePath);
    CountMalformed = 0;
    if (!logfile.is_open()) {
        throw runtime_error("File not open: " + logFilePath);
    }

    regex pattern(R"(^(\S+\s+\S+)\s+(INFO|WARNING|ERROR|FATAL)\s+(.*)$)");
    
    vector<LogEvent> events;
    string line;
    smatch match;
    
    while (getline(logfile, line)) {
        // printf("Parsing line: %s\n", line.c_str());
        
        if (regex_match(line, match, pattern)) {
            LogEvent event;
            event.timestamp = match[1];
            event.severity = parseSeverity(match[2]);
            event.message = match[3];
            events.push_back(event);
        } else {
            cerr << "Line does not match format: " << line << endl;
            // CountMalformed++;
        }
    }
    // printf("Total malformed lines: %d\n", CountMalformed);
    return events;
}

int LogParser::getCountMalformed() const {
    return CountMalformed;
}