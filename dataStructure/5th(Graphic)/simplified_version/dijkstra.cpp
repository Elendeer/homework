/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-22 21:09:05
 * @Description  :
*********************************************/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N];
int n, m;

int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; ++ i ) {
        int t = -1;
        for (int j = 1; j <= n; ++ j )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        st[t] = true;

        for (int j = 1; j <= n; ++ j )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main() {
    memset(g, 0x3f, sizeof g );

    cin >> n >> m;
    int a, b, c;
    while (m -- ) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}