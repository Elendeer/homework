/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-02 18:56:23
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-02 19:45:31
 * @Description  :
*********************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], n;

int main () {
    cin >> n;
    for (int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }

    for (int d = 1; d < n; ++ d ) {
        int tmp = a[d];

        // 找到插入点j
        int j = 0;
        for (; j < d; ++ j ) {
            if (tmp <= a[j]) {
                break;
            }
        }

        // 插入
        for (int k = d; k > j; -- k ) {
            a[k] = a[k - 1];
        }
        a[j] = tmp;
    }

    for (int i = 0; i < n; ++ i ) {
        cout << a[i] << " ";
    }

    return 0;
}
