#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include"Token.h"
#include"Error.h"

std::vector<std::string> Split(std::string &String, char ch, char escape = '\0');
std::string ReadSource(std::string SourceFileName);
std::string PreprocessSource(std::string &str);

int main() {
	std::string Source = ReadSource("Example.rlc");
	std::string PreProcessedSource = PreprocessSource(Source);

	std::stringstream ss;
	ss << "// This file was compiled by the KRCTP.\n"
	      "// (Kelvin's ResourCe TransPiler)\n";

	auto Lines = Split(PreProcessedSource, '\n');
	
	std::vector<LineContents*> TokenizedData;
	
	size_t LineNumber = 0;
	for (auto &Line : Lines) {
		LineNumber++;

		try {
			LineContents *TokenizedLine = new LineContents(Line, LineNumber);
			TokenizedData.push_back(TokenizedLine);
		} catch (SyntaxError Error) {
			ReportSyntaxError(Error);
			return -1;
		}
	}

	for (auto Line : TokenizedData) {
		ss << Line->GetCompiledContents();
	}

	std::ofstream Outfile("out.h");
	Outfile << ss.str();
	Outfile.close();
}