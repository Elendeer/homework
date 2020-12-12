<!--
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-10 23:43:49
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-11 21:35:56
 * @Description  :
-->

# Concept

Construct a mini interpreter using the knowledge of fundamentals of compiling.

- 总行数;
- 空行数;
- 注释;
- 函数;

## Grammar

## Lexer

```cpp
// Token的类型，使用枚举增加可读性
enum TokenType {
    ANY,
    NEWLINE,
    COMMENT_START,
    COMMENT_END,
};

class Token {

private:
    // 每个Token有一个表示自己的类型的成员变量
    TokenType m_type;

public:
    Token();
    ~Token();

    // 返回此Token的类型
    TokenType getType() const;
};


class Lexer {
private:
    // 存放输入的字符串（即C语言源代码
    string m_text;

    // 存放下标
    int m_pos;

    // 当前下标对应的字符
    char m_current_char;


    // 返回 m_pos + 1 处的字符，用于判断多个字符组成的Token
    char peek();

    // m_pos向前并更新 m_current_char
    void advance();

    // 跳过空格
    void skip_whitespace();

public:
    Lexer(string text);

    // 面向上层的接口，返回下一个Token
    Token get_next_token();
};

```

## Parser

```cpp
class Parser {
private :
    Lexer m_lexer;

    Token m_current_token;

public :
    void parse();
};
```
