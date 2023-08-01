#include"SyntaxError.h"

SyntaxError::SyntaxError(std::string ErrorMessage,
						 std::string HelpMessage,
						 size_t LineNumber,
						 std::string Line) : std::exception() {
	ErrMsg = ErrorMessage;
	HelpMsg = HelpMessage;
	this->LineNumber = LineNumber;
	this->Line = Line;
}

std::string SyntaxError::GetErr() {
	return ErrMsg;
}

std::string SyntaxError::GetHelpInfo() {
	return HelpMsg;
}

size_t SyntaxError::GetLineNumber() {
	return LineNumber;
}

std::string SyntaxError::GetLine() {
	return Line;
}