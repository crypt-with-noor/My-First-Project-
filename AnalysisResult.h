#ifndef ANALYSIS_RESULT_H
#define ANALYSIS_RESULT_H

#include <string>
#include <vector>

class AnalysisResult {
private:
    int score;
    std::vector<std::string> indicators;

public:
    AnalysisResult();
    void addIndicator(const std::string& indicator, int points);
    int getScore() const;
    const std::vector<std::string>& getIndicators() const;
    std::string getRiskLevel() const;
};

#endif
