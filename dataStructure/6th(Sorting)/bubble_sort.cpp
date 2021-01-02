/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-01-02 18:02:29
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-01-02 18:15:32
 * @Description  :
*********************************************/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], n;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++ i )
        for (int j = 0; j < n - i - 1; ++ j )
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);


    for (int i = 0; i < n; ++ i ) {
        cout << a[i] << " ";
    }


    return 0;
}
