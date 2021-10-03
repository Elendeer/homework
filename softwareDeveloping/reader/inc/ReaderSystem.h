/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-09-18 15:07:41
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-09-18 17:09:25
 * @Description  :
*********************************************/
#ifndef READER_INC_READERSYSTEM_H_
#define READER_INC_READERSYSTEM_H_

#include "UIDisplayer.h"
#include "SingleLinkedList.h"

#include <string>

class Data {
public:
    std::string _no;
    std::string _name;
    std::string _sex;
    std::string _departement;
    std::string _papers_state;

    Data(std::string no = "-1", std::string name = "unknow",
        std::string sex = "unknow", std::string departement = "unknow",
        std::string paper_state = "unknow") :
            _no(no), _name(name), _sex(sex), _departement(departement),
            _papers_state(paper_state) {}

    ~Data() {}

    Data & operator = (const Data & obj) {
        _no = obj._no;
        _name = obj._name;
        _sex = obj._sex;
        _departement = obj._departement;
        _papers_state = obj._papers_state;

        return *this;
    }
};

class ReaderSystem {
private:
    UIDisplayer _ui_displayer;
    SingleLinkedList<Data> _list;

    void main();
    void browse();
    void add();
    void search();
    void modify();
    void loss();

public:
    ReaderSystem();
    ~ReaderSystem();

    void run();
};

#endif
