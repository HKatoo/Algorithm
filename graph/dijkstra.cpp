#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
const int INF = 1e9;

struct edge {
    int to;
    int cost;
};

//単一始点最短経路問題
int main() {
    ifstream in("test.txt");
    cin.rdbuf(in.rdbuf());

    int v, e, start;  //頂点数,辺の数
    cin >> v >> e >> start;
    vector<edge> G[v];
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e1 = {b, c};
        edge e2 = {a, c};
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    // pair<暫定的な最短距離,頂点番号>
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        que;
    int d[v];  // スタートからの最短距離
    fill(d, d + v, INF);
    que.push({0, start});
    d[start] = 0;

    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();
        int ver = p.second;
        if (d[ver] < p.first) continue;
        for (int i = 0; i < G[ver].size(); i++) {
            edge e = G[ver][i];
            if (d[e.to] > d[ver] + e.cost) {
                d[e.to] = d[ver] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (d[i] != INF) cout << start << " -> " << i << " : " << d[i] << endl;
    }
}
