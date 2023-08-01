#include<iostream>
#include<sstream>
#include<cstring>
#include"Token.h"

#define ONE_CHAR_TOKENS				"=;"
#define VAR_FORMAT					"VAR <Name> = <Value>;"

std::string Trim(std::string &str);

std::string FirstToken(std::string &Source, size_t &End, size_t Start = 0) {
	// Define the begin position
	size_t PosBegin = End;
	
	// Skip the whitespace
	while (isspace(Source[PosBegin]))
		PosBegin++;
	
	// Check for single-character tokens
	for (int i = 0; i < strlen(ONE_CHAR_TOKENS); i++) {
		char ch = ONE_CHAR_TOKENS[i];
		if (ch == Source[PosBegin]) {
			End = PosBegin + 1;
			char Buffer[2] = { ch, 0 };
			std::string str = Buffer;
			return str;
		}
	}

	// Now go to the next whitespace
	size_t PosEnd = PosBegin;

	bool Comment = false;
	while (isalnum(Source[PosEnd]) || PosEnd - PosBegin == 0 || Comment) {
		if (Comment) {
			if (Source[PosEnd] == '"') {
				if (Source[PosEnd-1] != '\\') {
					PosEnd++;
					Comment = false;
					break;
				}
			}

			PosEnd++;
			continue;
		}
		
		if (Source[PosEnd] == '"') {
			Comment = true;
		}

		PosEnd++;
	}
	
	End = PosEnd;
	return Source.substr(PosBegin, PosEnd - PosBegin);
}

std::string FirstToken(std::string &Source) {
	size_t End;
	return FirstToken(Source, End);
}

LineContents::LineContents(std::string &Source, size_t LineNumber) {
	size_t End = 0;
	std::string Token = FirstToken(Source, End);

	if (Source.empty()) {
		Type = LineType::TYPE_NULL;
		return;
	}

	for (auto &ch : Token)
		if (isupper(ch))
			ch += 'a' - 'A';

	if (Token == "var") {
		Type = LineType::TYPE_DECLARATION;

		std::string NameToken = FirstToken(Source, End, End);

		if (!isalpha(NameToken[0])) {
			std::stringstream ss;
			ss << "Unexpected token \"" << NameToken << '"';

			throw SyntaxError(ss.str(), "Format for VAR statement: " VAR_FORMAT "\n"
							  "The name must be made up of of letters and numbers, but must start with a letter.",
							  LineNumber, Trim(Source));
		}

		std::string TokenEquals = FirstToken(Source, End, End);

		if (TokenEquals != "=") {
			std::stringstream ss;
			ss << "Unexpected token \"" << TokenEquals << '"';

			throw SyntaxError(ss.str(), "Format for VAR statement: " VAR_FORMAT "\n"
							  "After the name, there should be an equals sign.",
							  LineNumber, Trim(Source));
		}

		std::string Value = FirstToken(Source, End, End);

		std::string Semicolon = FirstToken(Source, End, End);

		if (Semicolon != ";") {
			std::stringstream ss;
			ss << "Unexpected token \"" << TokenEquals << '"';

			throw SyntaxError(ss.str(), "Format for VAR statement: " VAR_FORMAT "\n"
							  "A semicolon is required after the value.",
							  LineNumber, Trim(Source));
		}

		Data.DeclarationData.Name = NameToken;
		Data.DeclarationData.Value = Value;
	}
}

std::string LineContents::GetCompiledContents() {
	if (Type == LineType::TYPE_NULL)
		return "";
	
	switch (Type) {
		case LineType::TYPE_DECLARATION: {
			std::string Name = Data.DeclarationData.Name;
			std::string Value = Data.DeclarationData.Value;
			std::stringstream ss;
			ss << "#ifndef " << Name << "\n"
				"#define " << Name << " " << Value << "\n"
				"#endif\n";
			return ss.str();
		} break;
	}
}

// bool DeclParse(std::string &Source) {

// }