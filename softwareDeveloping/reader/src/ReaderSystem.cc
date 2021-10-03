/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-09-18 15:31:05
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-09-18 17:21:31
 * @Description  :
*********************************************/

#include "../inc/ReaderSystem.h"

#include <fstream>

using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

using std::cin;
using std::cout;
using std::endl;

ReaderSystem::ReaderSystem() {}
ReaderSystem::~ReaderSystem() {}

void ReaderSystem::run() {
    ifstream fin;
    fin.open("reader_utf-8.txt", ios::in);

    string tmp_str;
    while (fin >> tmp_str) {
        string no = tmp_str;
        string name;
        string sex;
        string departement;
        string papers_state;

        fin >> name >> sex >> departement >> papers_state;

        _list.insert(
            Data(no, name, sex, departement, papers_state)
        );
    }
    fin.close();

    main();
}

void ReaderSystem::main() {
    int op;

    while (true) {
        _ui_displayer.clearScreen();
        _ui_displayer.showMain();
        cin >> op;

        switch (op) {
            case 1:
                browse();
                break;
            case 2:
                add();
                break;
            case 3:
                search();
                break;
            case 4:
                modify();
                break;
            case 5:
                loss();
                break;
            case 0:
                return;
            default:
                cout << "no this option." << endl;
                break;
        }

        _ui_displayer.pause();
    }
}
void ReaderSystem::browse() {
    _ui_displayer.clearScreen();
    _ui_displayer.showBrowse();

    for (int i = 0; i < _list.size(); ++ i ) {
        Data data = _list[i];
        cout << data._no << "\t"
            << data._name << "\t"
            << data._sex << "\t"
            << data._departement << "\t"
            << data._papers_state << "\t"
            << endl;
    }

}
void ReaderSystem::add() {
    _ui_displayer.clearScreen();
    _ui_displayer.showAdd();

    string no;
    string name;
    string sex;
    string departement;
    string papers_state;

    cin >> no >> name >> sex >> departement >> papers_state;

    _list.insert(
        Data(no, name, sex, departement, papers_state)
    );

}
void ReaderSystem::search() {
    _ui_displayer.clearScreen();
    _ui_displayer.showSearch();

    string no;
    cin >> no;

    for (int i = 0; i < _list.size(); ++ i ) {
        Data data = _list[i];
        if (data._no == no) {
            cout << "No\tName\tSex\tDepartment\tIfPaperLossing" << endl;
            cout << data._no << "\t"
                << data._name << "\t"
                << data._sex << "\t"
                << data._departement << "\t"
                << data._papers_state << "\t"
                << endl;
            return ;
        }
    }

    cout << "No found" << endl;

}
void ReaderSystem::modify() {
    _ui_displayer.clearScreen();
    _ui_displayer.showModify();

    string no;
    cin >> no;

    for (int i = 0; i < _list.size(); ++ i ) {
        Data data = _list[i];
        if (data._no == no) {
            cout << "before: " << endl;
            cout << "No\tName\tSex\tDepartment\tIfPaperLossing" << endl;
            cout << data._no << "\t"
                << data._name << "\t"
                << data._sex << "\t"
                << data._departement << "\t"
                << data._papers_state << "\t"
                << endl;

            string no;
            string name;
            string sex;
            string departement;
            string papers_state;

            cin >> no >> name >> sex >> departement >> papers_state;

            _list[i] = Data(no, name, sex, departement, papers_state);

            return ;
        }
    }
    cout << "No found" << endl;
}
void ReaderSystem::loss() {
    _ui_displayer.clearScreen();
    _ui_displayer.showLoss();

    string no;
    cin >> no;
    for (int i = 0; i < _list.size(); ++ i ) {
        Data data = _list[i];
        if (data._no == no) {
            _list[i]._papers_state = "1";

            return ;
        }
    }
    cout << "No found" << endl;
}