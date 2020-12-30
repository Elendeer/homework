/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 20:50:39
 * @Description  :
*********************************************/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

// For getcwd(...)
#include <direct.h>
// Using different address breaking character in different platform.
#define ADDRESS_BREAK '\\'


#elif __linux__

// For readlink(...) & getcwd(...)
#include <unistd.h>

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '/'


#endif

#include "../inc/AddressParser.hpp"


AddressParser::AddressParser() {
	using namespace std;

	char cwd[256];
	if (getcwd(cwd, 256) == NULL) {
		cout << "Path error" << endl;
		exit(1);
	}
	m_current_working_directory = cwd;
}

string AddressParser::getHelpPath() const {
	return getExecDiretory() + ADDRESS_BREAK + "doc" + ADDRESS_BREAK + "help.txt";
}


AddressParser::~AddressParser() {}

string AddressParser::getCwd() const {
	return m_current_working_directory;
}


string AddressParser::parseRelativePath(string path) {
	if (isAbsPath(path)) return path;

	// Count num of ../
	int up = 0;
	// Record the index of string for cutting.
	int idx = 0;

	for (int i = 0; i < (int)path.size(); ++ i ) {

		// Find the relative path prefix.
		if (i + 1 < (int)path.size()
			&& path[i] == '.') {

			// Found ./
			if (path[i + 1] == ADDRESS_BREAK) {
				idx = i + 1;

				// Skip next char
				++ i;
				continue;
			}
			// Found ../
			else if (i + 2 < (int)path.size()
					&& path[i + 1] == '.'
					&& path[i + 2] == ADDRESS_BREAK) {
				idx = i + 2;
				++ up;

				// Skip next two char
				i += 2;
				continue;
			}
			else {
				continue;
			}

		}
		else {
			break;
		}
	}

	string sub_rela_string = path.substr(idx);

	idx = m_current_working_directory.size();
	// Throw some suffixal path of current working directory away.
	for (int i = (int)m_current_working_directory.size() - 1; i >= 0 && up; -- i) {
		if (m_current_working_directory[i] == ADDRESS_BREAK) {
			idx = i + 1;
			-- up;
		}
	}

	// Abandon repetive ADDRESS_BREAK if exist.
	if (m_current_working_directory[idx - 1] == ADDRESS_BREAK) -- idx;

	string sub_cwd_string = m_current_working_directory.substr(0, idx);


	// std::cout << sub_cwd_string << std::endl;

	return sub_cwd_string + sub_rela_string;
}
