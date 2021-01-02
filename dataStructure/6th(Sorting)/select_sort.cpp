/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-02 18:27:25
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-02 18:44:10
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

    for (int i = 0; i < n - 1; ++ i ) {
        int min = a[i];
        int idx = i;
        for (int j = i; j < n; ++ j) {
            if (a[j] < min) {
                min = a[j];
                idx = j;
            }
        }
        swap(a[i], a[idx]);
    }
    for (int i = 0; i < n; ++ i ) {
        cout << a[i] << " ";
    }


    return 0;
}
