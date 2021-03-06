/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-01 14:55:26
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 18:00:37
 * @Description  :
*********************************************/

#ifndef __ANALYZER_HPP__
#define __ANALYZER_HPP__


#include "Interpreter.hpp"
#include "AddressParser.hpp"
#include "FileReader.hpp"

#include "Controller.hpp"

class Analyzer {
    using string = std::string;
private:
    // Interpreter* m_interpreter;
    AddressParser m_address_parser;
    FileReader m_file_reader;
    Controller m_controller;

    std::string m_analyzing_path;

    // Absolute path is needed.
    void fileMode(string file_path);
    void dirMode(string dir_path);

public:
    Analyzer();
    ~Analyzer();

    // Read command line arguments. Throw string exception
    // if invailid argument is met.
    void readComArgs(int argc, char * argv[]);

    // Start analyze. Throw string exceptions if without
    // available input or opening error is met.
    void analyze();

};

#endif