#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include "../../inc/AddressParser.hpp"

#include <sys/stat.h>

bool AddressParser::isDir(string path)
{

	struct _stat file_stat;
	if ((_stat(path.c_str(), &file_stat) == 0) && (file_stat.st_mode & _S_IFDIR)) {
		return true;
	}

	return false;
}

#endif
