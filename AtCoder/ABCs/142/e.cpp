#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = (1 << 12);
const ll INF = 1e10;

int n, m;
ll cost[MX];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i < MX; ++i) cost[i] = INF;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int keys = 0;
        for (int j = 0; j < b; ++j) {
            int c; cin >> c;
            --c;
            keys += (1 << c);
        }
        // cout << i << ' ' << keys << '\n';
        for (int j = 0; j < MX; ++j) {
            if (cost[j] == INF) continue;
            // cout << "j: " << j << ' ' << (j | keys) << '\n';
            cost[(j | keys)] = min(cost[(j | keys)], cost[j] + a); 
            // cout << "cost " << j << ' ' << cost[(j | keys)] << '\n';
        }
    }
    cost[(1 << n) - 1] == INF ? cout << -1 : cout << cost[(1 << n) - 1];
}
