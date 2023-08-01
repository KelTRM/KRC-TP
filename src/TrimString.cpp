#include<string>

std::string Trim(std::string &str) {
	size_t BeginTrim = 0;
	size_t EndTrim = str.length();

	for (int i = 0; i < str.length(); i++) {
		char Current = str[i];
		if (!isspace(Current)) {
			BeginTrim = i;
			break;
		}
	}

	for (int i = str.length() - 1; i > 0; i--) {
		char Current = str[i];
		if (isspace(Current)) continue;

		EndTrim = i;
		break;
	}

	return str.substr(BeginTrim, EndTrim - BeginTrim);
}