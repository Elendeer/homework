/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-23 20:44:28
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-23 20:47:28
 * @Description  :
*********************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;



const int N = 150010;
int h[N], e[N], w[N], ne[N], idx;
int n;

int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

vector<int> path;

int dijkstra() {
    memset(dist, 0x3f, sizeof dist );
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int distance = t.first, ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;
        path.push_back(ver);

        for (int i = h[ver]; i != -1; i = ne[i] ) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    memset(h, -1, sizeof h );

    n = 3;

    add(1, 2, 2);
    add(2, 3, 1);
    add(1, 3, 4);

    int len = dijkstra();
    cout << "Path : " << endl;
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Length : " << len << endl;


    return 0;
}