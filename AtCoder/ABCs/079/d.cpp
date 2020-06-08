#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1000000000;

int h, w, c;
vector<pair<int, int>> conn[10];

int cost[10];

vector<int> d;
void dijkstra(int s, vector<int>& d) {
    int n = 10;
    d.assign(n, INF);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) 
                v = j;
        }

        if (d[v] == INF) break;

        u[v] = true;
        for (auto edge : conn[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
            }
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            if (i != j) conn[i].push_back({j, c});
        }
    }

    for (int i = 0; i < 10; i++) {
        dijkstra(i, d);
        cost[i] = d[1];
        // cout << cost[i] << "\n";
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c;
            if (c != -1) {
                // cout << c << " " << cost[c] << '\n';
                ans += cost[c];
            }
        }
    }
    cout << ans;
}
