#pragma once

#include<string>
#include<vector>

typedef struct {
	std::vector<std::string> InputFiles;
	std::string OutputFile;
} CommandLineInfo_t;

CommandLineInfo_t ParseCommandLine(int argc, char **argv);