/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-01 14:56:46
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 15:35:36
 * @Description  :
*********************************************/
#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

class Controller {
private:
	bool m_test_mode;
	bool m_src_test_mode;
	bool m_token_test_mode;
    bool m_dir_mode;

public:
    Controller();
    ~Controller();

    bool isTestMode() const;
    bool isSrcTestMode() const;
    bool isTokenTestMode() const;
    bool isDirMode() const;

    void setTestMode();
    void setSrcTestMode();
    void setTokenTestMode();
    void setDirMode();
};

#endif