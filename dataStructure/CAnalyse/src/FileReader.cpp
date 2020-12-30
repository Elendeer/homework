/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 15:50:09
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 21:00:12
 * @Description  :
*********************************************/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '\\'


#elif __linux__

// Using different address breaking character in different platform.
#define ADDRESS_BREAK '/'


#endif

#include "../inc/FileReader.hpp"


FileReader::FileReader() {}
FileReader::~FileReader() {}

string FileReader::readHelp() {
    string help_path = m_address_parser.getExecDiretory() +
         ADDRESS_BREAK + "doc" + ADDRESS_BREAK + "help.txt";

    return readFile(help_path);
}

string FileReader::readFile(string path) {
    std::ifstream reader;
	string txt;

    std::cout << std::endl << m_address_parser.parseRelativePath(path) << std::endl;

	reader.open(m_address_parser.parseRelativePath(path), std::ios::in);

    if (!reader.good()) {
        std::cout << "opening error" << std::endl;
    }

	while (!reader.eof()) {
		// For reading bug in linux file.
		if (reader.peek() != (char)-1) {
			txt += reader.get();
		}
		else {
			reader.ignore();
		}
	}
	reader.close();

    return txt;
}

void FileReader::printDir() const {
    using std::cout;
    using std::endl;

	string exec_directory_string = m_address_parser.getExecDiretory();
	string cwd_string = m_address_parser.getCwd();

	cout << "exec directory : " << exec_directory_string << endl;
	cout << "cwd : " << cwd_string << endl;
}