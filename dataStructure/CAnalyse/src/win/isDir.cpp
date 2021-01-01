#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include "../../inc/AddressParser.hpp"

#include <direct.h>
#include <vector>
#include <io.h>

bool AddressParser::isDir(string path) {

	return false;
}

#endif
