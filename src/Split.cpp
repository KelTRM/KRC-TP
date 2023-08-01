#include<iostream>
#include<vector>

std::vector<std::string> Split(std::string &String, char ch, char escape = '\0') {
	std::vector<std::string> Vec;
	
	std::string str = String;
	size_t Position = 0;
	size_t Search = 0;

	std::string BeginStr;
	std::string EndStr;

	while (true) {
		char prev;
		do {
			Position = str.find(ch);
			if (Position == 0)
				break;
				// goto done;
			
			if (Position == std::string::npos) {
				// std::cout << "str = " << str;
				Vec.push_back(str);
				goto done;
			}

			prev = str[Position-1];
			Search = Position+1;
		} while (prev == escape);

		size_t Length = str.length();
		BeginStr = str.substr(0, Position);
		if (Position == Length) {
			Vec.push_back(BeginStr);
			break;
		}

		Vec.push_back(BeginStr);
		str = str.substr(Position+1);
	}

done:
	return Vec;
}