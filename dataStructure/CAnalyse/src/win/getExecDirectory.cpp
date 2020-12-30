/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:55:52
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 16:57:30
 * @Description  :
*********************************************/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '\\'

#include <windows.h>

#include "../../inc/AddressParser.hpp"

string AddressParser::getExecDiretory() const {
    TCHAR buff[256];
    int size = GetModuleFileName(NULL, buff, 255);

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

	return (char*)buff;
}

#endif