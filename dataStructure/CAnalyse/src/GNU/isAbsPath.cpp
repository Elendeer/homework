/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 20:51:19
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 20:57:41
 * @Description  :
*********************************************/

#ifdef __linux__

#include "../../inc/AddressParser.hpp"

bool AddressParser::isAbsPath(string path) {
    if (path.at(0) == '/') {
            return true;
    }
    return false;
}


#endif
