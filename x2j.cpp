// Included Libraries:
// 
//      TinyXML2            https://github.com/leethomason/tinyxml2/
//      json                https://github.com/nlohmann/json
// 

#include "xml2json.hpp"

int main(int argc,const char* argv[]){

	if (argc != 3) {
		printf("Usage: x2j <source.xml> <dest.json>\n");
		return 1;
	}

	const char* source = argv[1];
	const char* dest = argv[2];

	X2J(source, dest);

	return 0;
}