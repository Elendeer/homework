/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:56:11
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 16:45:36
 * @Description  :
*********************************************/

#ifdef __linux__

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '/'

// For readlink(...)
#include <unistd.h>

#include "../../inc/AddressParser.hpp"

using std::string;

string AddressParser::getExecDiretory() const {
	char buff[256];
	int size = readlink("/proc/self/exe", buff, 255);

	if (size == -1 || size > 255) {
		std::cout << "Path reading error" << std::endl;
		exit(1);
	}

	// buf[size] = '\0';

	for (int i = size; i >= 0; -- i) {
		if (buff[i] == ADDRESS_BREAK) {
			buff[i] = '\0';
			break;
		}
	}

	return buff;
}

#endif

