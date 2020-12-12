/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-12 17:23:28
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-12 18:28:37
 * @Description  :
*********************************************/
#ifndef __HUFFMAN_HPP__
#define __HUFFMAN_HPP__

#include <iostream>
#include <vector>

class HNode {
private :
	int m_weight;
	char m_char;

	HNode * m_left;
	HNode * m_right;
	HNode * m_parent;

public :
	HNode(int weight, char c, HNode * left = nullptr, HNode * right = nullptr, HNode * parent = nullptr);
	~HNode();

	int getWeight() const;
	int getChar() const;

	HNode * getParent() const;
	HNode * getLeft() const;
	HNode * getRight() const;

	void setParent(HNode * parent);

};

class HuffmanEncoder {
private:
	std::string m_text;
	HNode * m_root;
	std::vector<int> m_encode;

	void dfs(HNode * p);

public:
	HuffmanEncoder(std::string text);
	~HuffmanEncoder();

	HNode * encode();
};

#endif
