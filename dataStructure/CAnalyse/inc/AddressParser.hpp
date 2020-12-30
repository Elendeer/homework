/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 15:55:11
 * @Description  :
*********************************************/

#ifndef __ADDRESS_PARSER_HPP__
#define __ADDRESS_PARSER_HPP__

#include <iostream>
#include <string>

using std::string;


class AddressParser {
private:
	string m_current_working_directory;
	string m_main_directory;

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
	string parseRelativePath(string relative_path);

};


#endif
