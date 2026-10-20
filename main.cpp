#include "MessageAnalyzer.h"
#include <iostream>
#include <string>

int main() {
    MessageAnalyzer analyzer;
    std::string message;

    std::cout << "====================================\n";
    std::cout << " ScamSentry - Message Risk Analyzer\n";
    std::cout << "====================================\n";
    std::cout << "Educational rule-based checker. Do not enter real secrets.\n\n";
    std::cout << "Paste a message to analyze:\n> ";
    std::getline(std::cin, message);

    if (message.empty()) {
        std::cout << "No message entered. Exiting.\n";
        return 0;
    }

    const AnalysisResult result = analyzer.analyze(message);
    std::cout << "\n--- Analysis Report ---\n";
    std::cout << "Risk score: " << result.getScore() << "/100\n";
    std::cout << "Risk level: " << result.getRiskLevel() << "\n";

    if (result.getIndicators().empty()) {
        std::cout << "No configured warning indicators were found.\n";
        std::cout << "This does NOT prove the message is safe.\n";
    } else {
        std::cout << "Warning indicators:\n";
        for (std::size_t i = 0; i < result.getIndicators().size(); ++i) {
            std::cout << "  " << (i + 1) << ". "
                      << result.getIndicators()[i] << "\n";
        }
    }

    std::cout << "\nSafety tip: verify through the organization's official app or website.\n";
    return 0;
}
