/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-02 21:05:18
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-02 23:49:42
 * @Description  :
*********************************************/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 16;
int a[N], n;

int h[M], e[M], ne[M], idx;
// add b to list a
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int s[N], s_idx;

void radix_sort() {
    // radix = 1111(二进制)
    int r = 0xf;
    for (int t = 0; t <= 7; ++ t) {
        // 取出某个位
        // 对某个位的桶排序
        for (int i = 0; i < n; ++ i ) {
            int c = (a[i] & r) >> (4 * t);
            add(c, a[i]);
        }

        // 遍历所有桶，取数放入原来的数组中
        int j = 0;
        for (int i = 0; i < 16; ++ i ) {
            for (int k = h[i]; k != -1; k = ne[k] ) {
                s[++ s_idx] = e[k];
            }
            while (s_idx) {
                a[j ++ ] = s[s_idx --];
            }
        }

        r <<= 4;
        // 清空桶，即所有链表
        idx = 0;
        memset(h, -1, sizeof h);
    }
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }

    radix_sort();

    for (int i = 0; i < n; ++ i ) {
        cout << a[i] << " ";
    }

    return 0;
}
