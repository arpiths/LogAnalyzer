
#include "log_analyzer.hpp"

#include <iostream>

void LogAnalyzer::analyze( const std::vector<LogEvent>& events) {

    severityCounts.clear();

    for (const auto& event : events) {

        std::string severity;

        switch (event.severity) {

            case Severity::INFO:
                severity = "INFO";
                break;

            case Severity::WARNING:
                severity = "WARNING";
                break;

            case Severity::ERROR:
                severity = "ERROR";
                break;

            case Severity::FATAL:
                severity = "FATAL";
                break;

            default:
                severity = "UNKNOWN";
        }

        severityCounts[severity]++;
    }

    // std::cout << "\n===== LOG ANALYSIS =====\n";
    
    // std::cout << "Total events: "
    //           << events.size() << "\n";

    // for (const auto& entry : severityCounts) {

    //     std::cout << entry.first
    //               << ": "
    //               << entry.second
    //               << "\n";
    // }

}

vector<LogEvent> LogAnalyzer::getErrors(const vector<LogEvent>& events) {
    vector<LogEvent> errorEvents;
    // std::cout << "==== ERROR EVENTS ====\n";
    for (const auto& event : events) {
        if (event.severity == Severity::ERROR || event.severity == Severity::FATAL) {
            errorEvents.push_back(event);
            // std::cout << event.timestamp
            //       <<": "
            //       << (event.severity==Severity::ERROR ? "ERROR" : "FATAL" )
            //       << ": "
            //       << event.message                  
            //       <<" \n";
                }
    }
    return errorEvents;
}

const std::map<std::string, int>&
LogAnalyzer::getSeverityCounts() const {
    return severityCounts;
}