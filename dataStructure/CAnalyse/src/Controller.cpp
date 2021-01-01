/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-01 15:04:21
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-01 15:36:42
 * @Description  :
*********************************************/
#include "../inc/Controller.hpp"

Controller::Controller() {
	m_test_mode = false;
	m_src_test_mode = false;
	m_token_test_mode = false;
}

Controller::~Controller() {}

bool Controller::isTestMode() const {
    return m_test_mode;
}
bool Controller::isSrcTestMode() const {
    return m_src_test_mode;
}
bool Controller::isTokenTestMode() const {
    return m_token_test_mode;
}
bool Controller::isDirMode() const {
    return m_dir_mode;
}


void Controller::setTestMode() {
    m_test_mode = true;
}
void Controller::setSrcTestMode() {
    m_src_test_mode = true;
}
void Controller::setTokenTestMode() {
    m_token_test_mode = true;
}
void Controller::setDirMode() {
    m_dir_mode = true;
}