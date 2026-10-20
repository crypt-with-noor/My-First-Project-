# ScamSentry — C++ Scam Message Risk Analyzer

## Overview
ScamSentry is a small defensive cybersecurity tool that checks a message for common scam and phishing indicators. It explains which rules matched and assigns a simple risk score.

## Features
- Analyze a message entered by the user
- Detect common urgency, prize, account-warning, and credential-request phrases
- Flag URL patterns that deserve extra checking, such as URL shorteners and plain HTTP links
- Display matched indicators and a risk category
- Includes sample messages for practice

## OOP concepts
- `MessageAnalyzer` class encapsulates analysis rules
- `AnalysisResult` class stores the result
- Private helper functions keep implementation details inside the class
- Public methods provide a simple interface

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o scamsentry
./scamsentry
```
On Windows:
```powershell
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o scamsentry.exe
.\scamsentry.exe
```

## Example
Input:
`Your account is locked! Verify your password immediately at http://example.test`

The tool may report multiple indicators and a high-risk label.

## Important limitation
This is a rule-based learning project, not a real-time security product. It can produce false positives and false negatives. Never decide whether a message is safe based only on this tool, and never enter real passwords or sensitive messages.
