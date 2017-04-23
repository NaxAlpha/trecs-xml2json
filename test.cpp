// Included Libraries:
// 
//      TinyXML2            https://github.com/leethomason/tinyxml2/
//      json                https://github.com/nlohmann/json
// 

#include "tinyxml2.h"
#include "json.hpp"
#include "xml2json.hpp"
#include <string.h>
#include <fstream>

using namespace tinyxml2;
using json = nlohmann::json;

#define ERROR(x)

int main() {

	XMLError Status;

	XMLDocument doc;
	Status = doc.LoadFile("test.xml");
	if (Status != XMLError::XML_SUCCESS) {
		ERROR("Unable to load XML file\n");
		return -1;
	}
	
	auto tables = trecs_xml_to_json(doc);

	std::ofstream o("result.json");
	o << tables << std::endl;
	o.close();

    return 0;
}