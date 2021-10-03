/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-10-03 11:14:21
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-10-03 11:40:36
 * @Description  :
*********************************************/
#include <cstdio>

static int main_return = 0;
static int test_count = 0;
static int test_pass = 0;

// This is a macro for testing program.
// Form of parameter 'equality' is '(expect) sign (actual)'.
// For example: (expect) == (actual)
// For example: (expect) > (actual)
//
// Parameter 'expect' is fill by the expect value.
// 'actual' is fill by the actual value which usually is
// the return value of a function or some modifying variable.
//
// Parameter 'format' is the format of tested function or variable,
// for example: "%d" for int ; "%lf" for double.
#define EXPECT_EQ_BASE(equality, expect, actual, format)\
    do {\
        ++test_count;\
        if (equality)\
            ++test_pass;\
        else {\
            fprintf(stderr, "%s%d: expect: " format "actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_return = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")