/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 20:51:19
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 20:55:57
 * @Description  :
*********************************************/

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include "../../inc/AddressParser.hpp"

bool AddressParser::isAbsPath(string path) {
    if (path.at(0) >= 'A' && path.at(0) <= 'Z'
        && path.at(1) == ':') {
            return true;
        }
    return false;
}

#endif