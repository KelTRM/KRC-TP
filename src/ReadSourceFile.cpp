#include<iostream>
#include<cstring>

std::string ReadSource(std::string SourceFileName) {
	FILE *File = fopen(SourceFileName.c_str(), "rb");
	fseek(File, 0, SEEK_END);
	size_t FileSize = ftell(File);
	fseek(File, 0, SEEK_SET);

	char *StrC = (char*)malloc(FileSize+1);
	fread((void*)StrC, 1, FileSize, File);
	StrC[FileSize] = 0;

	std::string str = StrC;
	free(StrC);
	
	return str;
}