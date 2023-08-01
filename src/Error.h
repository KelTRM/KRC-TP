#pragma once

#include"SyntaxError.h"
#include"TermColors.h"

#define ReportSyntaxError(Error, SourceFile)								\
					printf(TERM_COLOR_RED"Syntax Error on %s:%zu %s\n"		\
						   TERM_COLOR_BLUE "Help: %s\n" TERM_COLOR_DEFAULT	\
						   "\"%s\"\n",										\
						   SourceFile.c_str(),								\
						   Error.GetLineNumber(),							\
						   Error.GetErr().c_str(),							\
						   Error.GetHelpInfo().c_str(),						\
						   Error.GetLine().c_str())
