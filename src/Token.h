#pragma once

#include<string>
#include"SyntaxError.h"
#include<string.h>

enum class LineType {
	TYPE_NULL,
	TYPE_DECLARATION,
};

union TokenData {
	struct {
		std::string Name;
		std::string Value;
	} DeclarationData;
	TokenData() { memset(this, 0, sizeof(*this)); }
	~TokenData() { memset(this, 0, sizeof(*this)); }
};

class LineContents {
public:
	LineContents(std::string &Source, size_t LineNumbers);
	std::string GetCompiledContents();

private:
	std::string Source;
	LineType Type;
	size_t LineNumber;

	union TokenData Data;
};