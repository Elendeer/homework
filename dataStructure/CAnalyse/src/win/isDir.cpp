#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include "../../inc/AddressParser.hpp"

bool AddressParser::isDir() {
	return false;
}

#endif
