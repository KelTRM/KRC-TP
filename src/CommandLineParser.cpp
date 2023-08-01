#include"CommandLineParser.h"
#include<vector>

#define STATE_DEFAULT			0x01
#define STATE_RECIEVE_OUT_FILE	0x02

std::string ReadSource(std::string SourceFileName);

CommandLineInfo_t ParseCommandLine(int argc, char **argv) {
	CommandLineInfo_t CmdLine;

	std::vector<std::string> InputFiles;
	uint64_t State = STATE_DEFAULT;

	for (int i = 1; i < argc; i++) {
		switch (State) {
			case STATE_DEFAULT: {
				if (argv[i][0] == '-') {
					char ch = argv[i][1];
					switch (ch) {
						case 'o': {
							State = STATE_RECIEVE_OUT_FILE;
							break;
						}
					}
				} else {
					CmdLine.InputFiles.push_back(argv[i]);
				}
			} break;
			case STATE_RECIEVE_OUT_FILE: {
				if (!CmdLine.OutputFile.empty()) {
					printf("Error: more than one output file given\n");
					exit(-1);
				}
				CmdLine.OutputFile = argv[i];
				State = STATE_DEFAULT;
			} break;
		}
	}

	return CmdLine;
}