#ifndef __HUFFMAN_HPP__
#define __HUFFMAN_HPP__

#include <iostream>

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

};

class HuffmanEncoder {
private:
	std::string m_text;

public:
	HuffmanEncoder(std::string text);
	~HuffmanEncoder();

	HNode * encode();
};

#endif
