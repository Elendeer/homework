#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include "../../inc/AddressParser.hpp"

#include <direct.h>
#include <io.h>

using std::vector;
using std::string;

vector<string> AddressParser::getSubPaths(string dir_path) {
    _chdir(dir_path.c_str());

    vector<string> paths;

    _finddata_t file;
	long lf;
    if ((lf = _findfirst((dir_path + "*").c_str(), &file)) == -1) {
        throw (string)"path error";
    }
    else {
        while(_findnext(lf, &file) == 0) {
            if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
                continue;

            paths.push_back(file.name);
        }
        _findclose(lf);
    }

    _chdir(m_current_working_directory.c_str());
    return paths;
}

#endif