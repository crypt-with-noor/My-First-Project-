#ifndef MESSAGE_ANALYZER_H
#define MESSAGE_ANALYZER_H

#include <string>
#include "AnalysisResult.h"

class MessageAnalyzer {
private:
    bool containsAny(const std::string& text, const std::string phrases[], int count) const;
    std::string toLower(const std::string& text) const;

public:
    AnalysisResult analyze(const std::string& message) const;
};

#endif
