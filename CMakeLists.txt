cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(xml2json CXX)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.xml
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set (CMAKE_CXX_STANDARD 11)

add_executable(xml2json test.cpp tinyxml2.cpp)
add_executable(x2j x2j.cpp tinyxml2.cpp)