/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 18:09:45
 * @Description  :
*********************************************/

#ifndef __FILE_READER_HPP__
#define __FILE_READER_HPP__

#include "./AddressParser.hpp"

#include <fstream>

class FileReader {
private :
    AddressParser m_address_parser;

public :
    FileReader();
    ~FileReader();

    // Return a string containing contents of doc/help.txt.
    string readHelp();

    // Return a string containing contents of input file.
    // path sould point to file.
	// Throw a exception if opening error is met.
    string readFile(string path);

    // Print the cwd and directory of exe file.
    void printDir() const;

	// Return true if path is not pointing to a file but a directory.
	bool isDir(string path);
};

#endif
