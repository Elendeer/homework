/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-01 15:17:45
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 18:25:45
 * @Description  :
*********************************************/
#include "../inc/Analyzer.hpp"

#include <cstring>
#include <iostream>
#include <vector>

using std::string;
using std::vector;


Analyzer::Analyzer() {
    m_analyzing_path = "";
}
Analyzer::~Analyzer() {
}


void Analyzer::fileMode(string file_path) {
    using std::cout;
    using std::endl;

    cout << "file : " << file_path << endl;

	string src;
    // May throw opening error.
    src = m_file_reader.readFile(file_path);

	Lexer lexer(src);
	Parser parser(lexer);
	Interpreter interpreter(parser);

	// ==================== Test mode outputs ====================
	if (m_controller.isTestMode()) {
		cout << "========== Read source ==========" << endl;
		cout << src << endl;
		cout << "========== See tokens ==========" << endl;
		interpreter.printTokens();
		cout << endl;
		cout << "========== End of testing output ==========" << endl;
		cout << endl;
	}
	else {
		if (m_controller.isSrcTestMode()) {
			cout << "========== Read source ==========" << endl;
			cout << src << endl;
		}
		if (m_controller.isTokenTestMode()) {
			cout << "========== See tokens ==========" << endl;
			interpreter.printTokens();
			cout << endl;
		}
		if (m_controller.isSrcTestMode()
            || m_controller.isTokenTestMode()) {

			cout << "========== End of testing output ==========" << endl;
			cout << endl;
		}
	}
	// ==================== end of Test mode outputs ====================

	interpreter.interprete();
	interpreter.printResult();
    cout << endl;
}

void Analyzer::dirMode(string dir_path) {
    using std::cout;
    using std::endl;

    if (m_controller.isTestMode()) {
        cout << "directory mode : " << dir_path << endl;
    }

    string path = m_address_parser.parseRelativePath(dir_path);
    vector<string> sub_paths = m_address_parser.getSubPaths(path);

    for (auto s : sub_paths) {
        string abs_path = path + s;

        if (m_address_parser.isDir(abs_path)) {
            dirMode(abs_path);
        }
        else if (abs_path.back() == 'c' &&
        abs_path.at(abs_path.size() - 2) == '.') {
            fileMode(abs_path);
        }
        else {
            continue;
        }
    }
}


void Analyzer::readComArgs(int argc, char * argv[]) {
    using std::cout;
    using std::endl;

	for (int i = 1; i < argc; ++ i ) {
		if (strcmp(argv[i],"-t") == 0) {
            m_controller.setTestMode();
		}
		else if (strcmp(argv[i],"-src") == 0 || strcmp(argv[i],"-s") == 0) {
            m_controller.setSrcTestMode();
		}
		else if (strcmp(argv[i],"-token") == 0) {
            m_controller.setTokenTestMode();
		}
		else if (*(argv[i] + strlen(argv[i]) - 2) == '.'
				&& *(argv[i] + strlen(argv[i]) - 1) == 'c') {

			m_analyzing_path = argv[i];
            cout << "Input : " << m_analyzing_path << endl;
            cout << endl;
		}
		else if (strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0) {

            cout << m_file_reader.readFile(m_address_parser.getHelpPath()) << endl;
			return;
		}
		else if (strcmp(argv[i], "-path") == 0 || strcmp(argv[i], "-p") == 0) {
            cout << "cwd : " << m_address_parser.getCwd() << endl;
            cout << "exe dir : " << m_address_parser.getExecDiretory() << endl;
		}
		else if (m_address_parser.isDir(argv[i])) {
            m_controller.setDirMode();
			m_analyzing_path = argv[i];
            cout << "Input : " << m_analyzing_path << endl;
            cout << endl;
		}
		else {
            throw (string)"Invailid command line arguments!";
		}
	}
}

void Analyzer::analyze() {
    using std::cout;
    using std::endl;

    if (m_analyzing_path.size() == 0) {
        throw (string)"Without source or path input";
    }

    if (m_controller.isDirMode()) {
        dirMode(m_analyzing_path);
        return ;
    }
    else {
        string path = m_address_parser.parseRelativePath(m_analyzing_path);
        fileMode(path);
    }

    return;
}