/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-23 21:56:13
 * @Description  :
*********************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int g[N][N];
int n, m;

int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; ++ i ) {
        int t = -1;
        for (int j = 1; j <= n; ++ j )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        // 若不是第一个取到的点且到该点的距离为无穷
        // 则该点不可达，最小生成树不存在
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;

        if (i) res += dist[t];
        st[t] = true;

        // 注意对比Dijkstra的距离更新
        for (int j = 1; j <= n; ++ j ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main () {
    memset(g, 0x3f, sizeof g);

    // g[i][i] 取值对结果并没有影响，因此不用针对它初始化

    n = 4;
    g[1][2] = g[2][1] = 1;
    g[1][3] = g[3][1] = 2;
    g[1][4] = g[4][1] = 3;
    g[2][3] = g[3][2] = 2;
    g[3][4] = g[4][3] = 4;

    int t = prim();
    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", t);


    return 0;
}