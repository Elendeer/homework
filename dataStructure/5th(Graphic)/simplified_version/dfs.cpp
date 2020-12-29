/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-22 22:39:09
 * @Description  :
*********************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int n) {
    st[n] = true;
    cout << n << " ";
    for (int i = h[n]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            // other operations.
            st[j] = true;
            dfs(j);
        }
    }
}

int main () {
    memset(h, -1, sizeof h);

    add(1, 2, 1);
    add(2, 3, 1);
    add(3, 4, 1);
    add(4, 5, 1);
    add(1, 4, 1);

    dfs(1);

    return 0;
}