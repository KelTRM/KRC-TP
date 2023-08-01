#pragma once

#include"SyntaxError.h"

#define ReportSyntaxError(Error)									\
					printf("Syntax Error on line %zu: %s\n"			\
									"Help: %s\n"					\
									"\"%s\"\n",						\
									Error.GetLineNumber(),			\
									Error.GetErr().c_str(),			\
									Error.GetHelpInfo().c_str(),	\
									Error.GetLine().c_str())
