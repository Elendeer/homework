/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 16:49:21
 * @Description  :
*********************************************/

#ifndef __ADDRESS_PARSER_HPP__
#define __ADDRESS_PARSER_HPP__

#include <iostream>
#include <string>
#include <vector>


class AddressParser {
	using string = std::string;

private:
	string m_current_working_directory;
	string m_main_directory;

	bool isAbsPath(string path);

public:
	AddressParser();
	~AddressParser();

	// Get current working directory.
	string getCwd() const;

	// Get directory of main exec file.
	string getExecDiretory() const;

	// Get the path of help.txt.
	string getHelpPath() const;

	// Parse a relative path to a absolute path.
	string parseRelativePath(string path);

	// Return true if path is not pointing to a file but a directory.
	bool isDir(string path);

	// Get sub paths of a directory.
	std::vector<string> getSubPaths(string dir_path);
};


#endif
