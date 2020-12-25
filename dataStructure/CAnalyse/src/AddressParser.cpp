#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include <direct.h>
#define ADDRESS_BREAK '\\'


#elif __linux__

#include <unistd.h>
#define ADDRESS_BREAK '/'

#endif

#include "../inc/AddressParser.hpp"

AddressParser::AddressParser() {
	using namespace std;

	char cwd[256];
	if (getcwd(cwd, 256)) {
		cout << "Work in path : " << cwd << endl;
	}
	else {
		cout << "Path error" << endl;
		exit(1);
	}
	m_current_working_directory = cwd;


}
AddressParser::~AddressParser() {}
