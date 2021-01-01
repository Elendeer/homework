#ifdef __linux__

#include "../../inc/AddressParser.hpp"

// For opendir(...)
#include <sys/types.h>
#include <dirent.h>

bool AddressParser::isDir(string path) {

	// DIR * p_dir = opendir(path.c_str());
	// if (p_dir == NULL) {
	// 	return false;
	// }

	// closedir(p_dir);
	// return true;
}

#endif
