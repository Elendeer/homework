#ifndef __ADDRESS_PARSER_HPP__
#define __ADDRESS_PARSER_HPP__

#include <iostream>
#include <string>

using std::string;


class AddressParser {
private:
	string m_current_working_directory;
	string m_main_directory;

	// Get directory of exe file. Only used in GNU.
	string GNUgetExecDiretory() const;

	// Get directory of exe file. Only used in MSWindows.
	string MSWINgetRunningDiretory() const;

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
