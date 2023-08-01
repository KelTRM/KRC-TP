#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include"Token.h"
#include"Error.h"
#include"CommandLineParser.h"

std::vector<std::string> Split(std::string &String, char ch, char escape = '\0');
std::string ReadSource(std::string SourceFileName);
std::string PreprocessSource(std::string &str);

int main(int argc, char **argv) {
	CommandLineInfo_t CommandLine = ParseCommandLine(argc, argv);
	if (CommandLine.InputFiles.size() == 0) {
		std::cout << "Error: No input files given!\n";
	}

	std::string Source = ReadSource(CommandLine.InputFiles[0]);
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

	std::ofstream Outfile(CommandLine.OutputFile);
	Outfile << ss.str();
	Outfile.close();
}