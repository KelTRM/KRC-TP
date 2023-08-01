#include<sstream>
#include<string>
#include<vector>
#include"Error.h"
#include"Token.h"

std::vector<std::string> Split(std::string &String, char ch, char escape = '\0');
std::string ReadSource(std::string SourceFileName);
std::string PreprocessSource(std::string &str);

bool TranspileFile(std::string SourceFilename, std::stringstream &SourceStream) {
	std::string Source = ReadSource(SourceFilename);
	std::string PreProcessedSource = PreprocessSource(Source);

	auto Lines = Split(PreProcessedSource, '\n');
	
	std::vector<LineContents*> TokenizedData;
	
	size_t LineNumber = 0;
	for (auto &Line : Lines) {
		LineNumber++;

		try {
			LineContents *TokenizedLine = new LineContents(Line, LineNumber);
			TokenizedData.push_back(TokenizedLine);
		} catch (SyntaxError Error) {
			ReportSyntaxError(Error, SourceFilename);
			return false;
		}
	}

	for (auto Line : TokenizedData) {
		SourceStream << Line->GetCompiledContents();
	}
	return true;
}