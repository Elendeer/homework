/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-03 20:13:54
 * @Description  :
*********************************************/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '\\'


#elif __linux__

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '/'


#endif

#include "../inc/FileReader.hpp"
#include <iostream>


using std::string;

FileReader::FileReader() {}
FileReader::~FileReader() {}

string FileReader::readFile(string abs_path) {
    std::ifstream reader;
	string txt;

	reader.open(abs_path, std::ios::in);

    if (!reader.good()) {

		throw (string)"opening error";
    }

	while (!reader.eof()) {
		// For reading bug in linux file.
		if (reader.peek() != (char)-1) {
			txt += reader.get();
		}
		else {
			reader.ignore();
		}
	}
	reader.close();

    return txt;
}