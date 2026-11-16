
#include "log_parser.hpp"
#include "log_analyzer.hpp"

#include <iostream>

int main(int argc, char* argv[]) {

    if (argc != 2) {

        std::cerr
            << "Usage: log_analyzer <log_file>\n";

        return 1;
    }

    try {

        LogParser parser;

        auto events = parser.parseFile(argv[1]);

        LogAnalyzer analyzer;

        analyzer.analyze(events);

        auto errorEvents = analyzer.getErrors(events);

        std::cout << "\n===== LOG ANALYSIS =====\n";
        
        std::cout << "Total events: "
                << events.size() << "\n";

        for (const auto& entry : errorEvents) {

            std::cout << entry.timestamp
                    << ": "
                    << entry.message
                    << "\n";
        }
        std::cout << "Total malformed events: " << parser.getCountMalformed() << std::endl;
        const auto& counts = analyzer.getSeverityCounts();

        std::cout << "\nSeverity distribution:\n";

        for (const auto& [severity, count] : counts) {
            std::cout << severity << ": " << count << '\n';
        }

    }
    catch (const std::exception& error) {

        std::cerr << "Error: "
                  << error.what() << "\n";

        return 1;
    }

    return 0;
}
