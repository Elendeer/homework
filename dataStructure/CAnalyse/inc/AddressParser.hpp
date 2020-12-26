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

	// Parse a relative path to a absolute path.
	string parseRelativePath(string relative_path);
	
};


#endif
