//==============================================================================//
//																				//
//		File:		xml2json.hpp												//
//		Author:		Nauman Mustafa												//
//		Updated:	April 23, 2017												//
//																				//
//		Licensed under the MIT License <http://opensource.org/licenses/MIT>.	//
//																				//
//==============================================================================//

#include <string>
#include <fstream>
#include "tinyxml2.h"
#include "json.hpp"

#ifndef NAX_XML_2_JSON
#define NAX_XML_2_JSON

#define X2J(src, dst) trecs_xml_to_json(src, dst)
#define XML2JSON(str) trecs_xml_to_json(str)

// Converts TRecs Result XML to JSON
nlohmann::json trecs_xml_to_json(tinyxml2::XMLDocument& doc) {
	// Get Top Element
	auto elem = doc.FirstChildElement("TRecsResult");

	// Output array
	nlohmann::json tables = nlohmann::json::array();

	// Iterate over all tables
	for (auto table = elem->FirstChildElement(); table != nullptr; table = table->NextSiblingElement()) {

		// Output Table
		nlohmann::json tab;

		// Copy table attributes
		for (auto atr = table->FirstAttribute(); atr != nullptr; atr = atr->Next()) {
			tab[atr->Name()] = atr->Value();
		}

		// Store cells
		nlohmann::json cells = nlohmann::json::array();

		// Iterate over all the cells
		for (auto cell = table->FirstChildElement(); cell != nullptr; cell = cell->NextSiblingElement()) {

			// Output cell
			nlohmann::json cel;

			// Copy cell attributes
			for (auto atr = cell->FirstAttribute(); atr != nullptr; atr = atr->Next()) {
				cel[atr->Name()] = atr->Value();
			}

			// Store cell
			cells.push_back(cel);
		}

		// Save cells
		tab["Cells"] = cells;

		// Store table
		tables.push_back(tab);
	}

	return tables;
}

// Converts trecs_xml string to json string
std::string trecs_xml_to_json(std::string trecs_xml) {

	// Convert to usable format for XMLDocument::Parse
	const char* data = trecs_xml.c_str();

	// Construct DOM and parse data
	tinyxml2::XMLDocument doc;
	doc.Parse(data, trecs_xml.size());

	// Process document
	nlohmann::json output = trecs_xml_to_json(doc);

	// Return results
	return output.dump();
}

// Converts Source file XML to JSON and saves to Destination file
void trecs_xml_to_json(std::string fSource, std::string fDest) {
	
	// Construct DOM and load xml file
	tinyxml2::XMLDocument doc;
	doc.LoadFile(fSource.c_str());

	// Process Document
	nlohmann::json output = trecs_xml_to_json(doc);

	// Save output to file
	std::ofstream out(fDest);
	out << output;
	out.close();

}

#endif