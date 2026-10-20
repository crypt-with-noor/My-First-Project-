#include "AnalysisResult.h"

AnalysisResult::AnalysisResult() : score(0) {}

void AnalysisResult::addIndicator(const std::string& indicator, int points) {
    indicators.push_back(indicator);
    score += points;
    if (score > 100) score = 100;
}

int AnalysisResult::getScore() const {
    return score;
}

const std::vector<std::string>& AnalysisResult::getIndicators() const {
    return indicators;
}

std::string AnalysisResult::getRiskLevel() const {
    if (score >= 60) return "HIGH";
    if (score >= 30) return "MEDIUM";
    return "LOW";
}
