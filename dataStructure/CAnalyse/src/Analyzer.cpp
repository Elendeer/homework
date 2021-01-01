/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-01 15:17:45
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 15:56:56
 * @Description  :
*********************************************/
#include "../inc/Analyzer.hpp"

#include <cstring>
#include <iostream>

Analyzer::Analyzer() {
    // m_interpreter = nullptr;
    m_analyzing_path = "";
}
Analyzer::~Analyzer() {
    // if (m_interpreter != nullptr) {
    //     delete m_interpreter;
    // }
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
            cout << "Input file : " << m_analyzing_path << endl;
		}
		else if (strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0) {

            m_file_reader.readFile(m_address_parser.getHelpPath());
			return;
		}
		else if (strcmp(argv[i], "-path") == 0 || strcmp(argv[i], "-p") == 0) {

		}
		else if (m_address_parser.isDir(argv[i])) {
			cout << "Your input is a dir" << endl;
            m_controller.setDirMode();
		}
		else {
            throw (string)"Invailid command line arguments!";
		}
	}
}

void Analyzer::analyze() {
    using std::cout;
    using std::endl;

    if (m_controller.isDirMode()) {
        cout << "haven't finish this mode" << endl;
        return ;
    }

    if (m_analyzing_path.size() == 0) {
        throw (string)"Without available input";
    }



    string path = m_address_parser.parseRelativePath(m_analyzing_path);

	string src;
    // May throw opening error.
    src = m_file_reader.readFile(path);

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

    return;
}