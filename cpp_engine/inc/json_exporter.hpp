#pragma once

#include "log_event.hpp"

#include <nlohmann/json.hpp>
#include <map>
#include <string>
#include <vector>

class JsonExporter {

public:

    nlohmann::json exportAnalysis(
        const std::vector<LogEvent>& events,
        const std::vector<LogEvent>& errors,
        const std::map<std::string, int>& severityCounts,
        int malformedCount
    );

};