#include<iostream>
#include<vector>

std::string PreprocessSource(std::string &str) {
	bool CurrentlyInComment = false;
	bool CurrentlyInString = false;
	std::string PreProcessedSource;

	for (int i = 0; i < str.length(); i++) {
		if (CurrentlyInComment) {
			char ch = str[i];
			if (ch != '\n')
				continue;
			
			PreProcessedSource += '\n';
			CurrentlyInComment = false;
			continue;
			// char LastChar = PreProcessedSource.back();
			// if (LastChar == '\0')
		}

		if (!CurrentlyInString) {
			char CurrentChar = str[i];

			if (i+1 < str.length()) {
				char ch1 = CurrentChar;
				char ch2 = str[i+1];
				if (ch1 == '/' && ch2 == '/') {
					// CommentCount++;
					CurrentlyInComment = true;
					continue;
				}
			}

			if (CurrentChar == '"') {
				if (i-1 >= 0) {
					CurrentlyInString = true;
				}
			}
		} else {
			char ch1 = str[i];
			char ch2 = str[i-1];
			if (ch2 != '\\' && ch1 == '"')
				CurrentlyInString = false;
		}

		if (str[i] == '\r')
			continue;
		PreProcessedSource += str[i];
	}
	return PreProcessedSource;
}