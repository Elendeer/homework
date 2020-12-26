/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-26 17:43:41
 * @Description  :
*********************************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int p[N];
int n, m;

// 定义边结构以及重载小于号运算符方便排序
struct Edge {
    int a, b, w;

    bool operator < (const Edge &W) const {
        return w < W.w;
    }
} edges[M];

// 并查集的核心，查找函数
int find(int a) {
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

int main() {
    // cin >> n >> m;

    // int a, b, c;
    // for (int i = 0; i < m; ++ i ) {
    //     scanf("%d%d%d", &a, &b, &c);
    //     edges[i] = {a, b, c};
    // }

    n = 4, m = 5;

    edges[0] = {1, 2, 1};
    edges[1] = {2, 3, 2};
    edges[2] = {3, 4, 4};
    edges[3] = {1, 4, 3};
    edges[4] = {1, 3, 2};

    sort(edges, edges + m);

    // 初始化并查集
    for (int i = 1; i <= n; ++ i ) p[i] = i;

    // 计算最小生成树权重和以及将某个节点加入连通块的次数
    int res = 0, cnt = 0;
    for (int i = 0; i < m; ++ i ) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);

        if (a != b) {
            p[a] = b;
            ++ cnt;
            res += w;
        }
    }

    if (cnt == n - 1) printf("%d\n", res);
    else puts("impossible");

    return 0;
}
