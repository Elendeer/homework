/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-09-18 12:03:52
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-09-18 17:19:15
 * @Description  :
*********************************************/

#include "../inc/UIDisplayer.h"

#include <iostream>

using std::cout;
using std::endl;

UIDisplayer::UIDisplayer() {}
UIDisplayer::~UIDisplayer() {}

void UIDisplayer::showMain() {
    cout << "********************************" << endl;
    cout << "    Reader Management System" << endl;
    cout << "*    1. Browse all readers     *" << endl;
    cout << "*    2. Add reader             *" << endl;
    cout << "*    3. Search reader          *" << endl;
    cout << "*    4. Modify reader          *" << endl;
    cout << "*    5. Lossing report         *" << endl;
    cout << "*    0. Back                   *" << endl;
    cout << "********************************" << endl;
    cout << "Input you operation please > " ;
}

void UIDisplayer::showBrowse() {
    cout << "********************************" << endl;
    cout << "*           Readers            *" << endl;
    cout << "********************************" << endl;
    cout << "No\tName\tSex\tDepartment\tIfPaperLossing" << endl;
}

void UIDisplayer::showAdd() {
    cout << "********************************" << endl;
    cout << "*           Add reader         *" << endl;
    cout << "********************************" << endl;
    cout << "Please input:" << endl;
    cout << " 1. No" << endl;
    cout << " 2. Name" << endl;
    cout << " 3. Sex (M/F)" << endl;
    cout << " 4. Department" << endl;
    cout << " 5. If papers lossing (0/1)" << endl;
    cout << "********************************" << endl;
}

void UIDisplayer::showSearch() {
    cout << "********************************" << endl;
    cout << "*           Search reader      *" << endl;
    cout << "********************************" << endl;
    cout << "Please input No: " ;
}

void UIDisplayer::showModify() {
    cout << "********************************" << endl;
    cout << "*           Modify reader      *" << endl;
    cout << "********************************" << endl;
    cout << "Please input:" << endl;
    cout << " 1. No of the reader you want to modify" << endl;
    cout << " 2. New No" << endl;
    cout << " 3. New Name" << endl;
    cout << " 4. New Sex (M/F)" << endl;
    cout << " 5. New Department" << endl;
    cout << " 6. New If papers lossing (0/1)" << endl;
    cout << "********************************" << endl;
}

void UIDisplayer::showLoss() {
    cout << "********************************" << endl;
    cout << "*     Papers lossing report    *" << endl;
    cout << "********************************" << endl;
    cout << "Please input the No of reader lossing papers:";
}

void UIDisplayer::clearScreen() {
    system("cls");
}
void UIDisplayer::pause() {
    system("pause");
}