#include "MessageAnalyzer.h"
#include <algorithm>
#include <cctype>

std::string MessageAnalyzer::toLower(const std::string& text) const {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return result;
}

bool MessageAnalyzer::containsAny(const std::string& text,
                                  const std::string phrases[], int count) const {
    for (int i = 0; i < count; ++i) {
        if (text.find(phrases[i]) != std::string::npos) return true;
    }
    return false;
}

AnalysisResult MessageAnalyzer::analyze(const std::string& message) const {
    AnalysisResult result;
    const std::string text = toLower(message);

    const std::string urgency[] = {
        "immediately", "urgent", "act now", "within 24 hours", "final warning"
    };
    const std::string prize[] = {
        "you won", "winner", "claim your prize", "free gift", "lottery"
    };
    const std::string account[] = {
        "account is locked", "account suspended", "verify your account",
        "unusual activity", "security alert"
    };
    const std::string credentials[] = {
        "password", "one-time code", "otp", "pin number", "login details"
    };

    if (containsAny(text, urgency, 5))
        result.addIndicator("Urgency or pressure language", 20);
    if (containsAny(text, prize, 5))
        result.addIndicator("Prize, gift, or lottery claim", 25);
    if (containsAny(text, account, 5))
        result.addIndicator("Account warning or verification request", 20);
    if (containsAny(text, credentials, 5))
        result.addIndicator("Mentions password, OTP, PIN, or login details", 25);

    if (text.find("http://") != std::string::npos)
        result.addIndicator("Contains a non-encrypted HTTP link", 15);

    const std::string shorteners[] = {
        "bit.ly/", "tinyurl.com/", "t.co/", "is.gd/"
    };
    if (containsAny(text, shorteners, 4))
        result.addIndicator("Contains a URL-shortener domain", 20);

    if (text.find("://") != std::string::npos &&
        text.find("https://") == std::string::npos &&
        text.find("http://") == std::string::npos)
        result.addIndicator("Contains an unusual link format", 10);

    return result;
}
