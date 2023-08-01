#pragma once

#include"SyntaxError.h"
#include"TermColors.h"

#define ReportSyntaxError(Error)											\
					printf(TERM_COLOR_RED"Syntax Error on line %zu: %s\n"	\
						   TERM_COLOR_BLUE "Help: %s\n" TERM_COLOR_DEFAULT	\
						   "\"%s\"\n\n",									\
						   Error.GetLineNumber(),							\
						   Error.GetErr().c_str(),							\
						   Error.GetHelpInfo().c_str(),						\
						   Error.GetLine().c_str())
