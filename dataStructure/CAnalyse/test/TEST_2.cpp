/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-05-07 16:38:46
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-07-21 23:55:09
 * @Description  :
*********************************************/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 20; // 1e5 + 10;
const int M = 1e6 + 10;

int ne[N];
char s[M], p[N];

int main() {
    int n, m;
    cin >> n >> p + 1 >> m >> s + 1;

    ne[1] = 1;
    for (int i = 2, j = 1; i <= n; ++ i ) {
        while ((j - 1) && p[j] != p[i]) j = ne[j];
        if (p[j] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 1, j = 1; i <= m; ++ i ) {
        while (j - 1 && p[j] != s[i]) j = ne[j];
        if (s[i] == p[j]) j ++ ;
        if (j - 1 == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}