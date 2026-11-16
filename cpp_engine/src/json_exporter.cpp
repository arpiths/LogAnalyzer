#include "json_exporter.hpp"

namespace {

std::string severityToString(Severity severity) {

    switch (severity) {

        case Severity::INFO:
            return "INFO";

        case Severity::WARNING:
            return "WARNING";

        case Severity::ERROR:
            return "ERROR";

        case Severity::FATAL:
            return "FATAL";

        default:
            return "UNKNOWN";
    }
}

}

nlohmann::json JsonExporter::exportAnalysis(
    const std::vector<LogEvent>& events,
    const std::vector<LogEvent>& errors,
    const std::map<std::string, int>& severityCounts,
    int malformedCount
) {

    nlohmann::json output;

    output["total_events"] = events.size();
    output["malformed_entries"] = malformedCount;

    output["severity_counts"] = severityCounts;

    output["errors"] = nlohmann::json::array();

    for (const auto& event : errors) {

        nlohmann::json error;

        error["timestamp"] = event.timestamp;
        error["severity"] = severityToString(event.severity);
        error["message"] = event.message;

        output["errors"].push_back(error);
    }

    return output;
}