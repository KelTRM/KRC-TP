#pragma once

#include<exception>
#include<string>

class SyntaxError : std::exception {
	std::string ErrMsg;
	std::string HelpMsg;
	size_t LineNumber;
	std::string Line;
public:
	SyntaxError(std::string ErrorMessage, std::string HelpMessage, size_t LineNumber, std::string Line);
	std::string GetErr();
	std::string GetHelpInfo();
	size_t GetLineNumber();
	std::string GetLine();
};