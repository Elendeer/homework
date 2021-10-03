/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-09-18 11:57:48
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-09-18 17:19:01
 * @Description  :
*********************************************/
#ifndef READER_INC_UIDISPLAYER_H_
#define READER_INC_UIDISPLAYER_H_

class UIDisplayer {
private:

public:
    UIDisplayer();
    virtual ~UIDisplayer();

    void showMain();

    void showBrowse();
    void showAdd();
    void showSearch();
    void showModify();
    void showLoss();

    void clearScreen();
    void pause();

};

#endif