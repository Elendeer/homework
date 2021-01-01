#ifdef __linux__

#include "../../inc/AddressParser.hpp"

// For opendir(...).
#include <sys/types.h>
// For DIR
#include <dirent.h>

#include <cstring>

using std::vector;
using std::string;

vector<string> AddressParser::getSubPaths(string dir_path) {
	vector<string> paths;

	DIR * p_dir = opendir(dir_path.c_str());

	if (p_dir == NULL) {
		throw (string)"dir opening error";
	}

	struct dirent * entry;
	while ((entry = readdir(p_dir)) != NULL) {
		if (strcmp(entry -> d_name, ".") == 0
				|| strcmp(entry -> d_name, "..") == 0) {
			continue;
		}

		paths.push_back(entry -> d_name);
	}

	closedir(p_dir);
	return paths;
}

#endif
