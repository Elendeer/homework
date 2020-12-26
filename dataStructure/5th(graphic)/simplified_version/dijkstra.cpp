/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-22 20:14:10
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-23 18:27:39
 * @Description  :
*********************************************/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 510;
int g[N][N];
int n, m;

int dist[N];
bool st[N];

vector<int> path;

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; ++ i ) {
        int t = -1;
        for (int j = 1; j <= n; ++ j )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        path.push_back(t); // 储存路径
        st[t] = true;

        for (int j = 1; j <= n; ++ j )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    path.push_back(n);

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main() {
    memset(g, 0x3f, sizeof g );

    n = 3; // 汇点为节点3
    g[1][2] = 2;
    g[2][3] = 1;
    g[1][3] = 4;

    int len = dijkstra();
    cout << "Path : " << endl;
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Length : " << len << endl;


    return 0;
}