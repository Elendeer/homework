#ifdef __linux__

#include "../../inc/AddressParser.hpp"

// For struct stat and stat(...).
#include <sys/stat.h>

bool AddressParser::isDir(string path) {
	struct stat file_stat;

	if ((stat(path.c_str(), &file_stat) == 0)
			&& (file_stat.st_mode & S_IFDIR)) {
		return true;
	}

	return false;
}

#endif
