/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-22 22:39:42
 * @Description  :
*********************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];
int q[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int n) {
    int hh = 0, tt = -1;
    st[n] = true;
    q[++ tt] = n;
    while (hh <= tt) {
        int t = q[hh ++ ];

        // other operations.
        cout << t << " ";

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                q[++ tt ] = j;
            }
        }
    }
    return ;
}

int main () {
    memset(h, -1, sizeof h);

    add(1, 2, 1);
    add(2, 3, 1);
    add(3, 4, 1);
    add(4, 5, 1);
    add(1, 4, 1);

    bfs(1);

    return 0;
}