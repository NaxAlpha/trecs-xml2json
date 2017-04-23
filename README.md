# TRecs Xml2Json Converter Module

TRecs Xml2Json Converter Module converts TRecs output XML to JSON efficiently using powerful C++ XML and JSON libraries.
Following is list of libraries used:

* [tinyxml2](https://github.com/leethomason/tinyxml2/)
* [json](https://github.com/nlohmann/json)

## Features

Following is a short list of features this module has:

* Convert using functions (C-like API)
* Convert files or strings
* Commandline Application Included (**x2j**)

## Usage

It doesn't require building before using. Simply include following files in your project to use this module:

* `json.hpp`
* `tinyxml2.h`
* `xml2json.hpp`
* `xml2json.cpp`
* `tinyxml2.cpp`

Example usages are:

* `X2J("test.xml", "out.json");`
* `std::string output_json = XML2JSON(source_json);`

## Build

To build test and commandline executable module, Follow these steps

* `git clone https://github.com/NaxAlpha/trecs-xml2json`
* `mkdir build && cd build`
* `cmake .. && make`
 
 Now run `x2j` with first argument as source **xml file** and second argument as destination **json file** as 
 `x2j src.xml out.json`

