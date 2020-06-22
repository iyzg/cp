#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int N = 500, C = 30;

int n, c;
// Cost from x - > y, grid, cost to turn into C for each group
ll cost[C][C], grid[N][N], gCost[3][C];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    // Convert all 1 indexed -> 0 indexed
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            --grid[i][j];

            for (int k = 0; k < c; ++k)
                gCost[(i + j) % 3][k] += cost[grid[i][j]][k];
        }
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }
    
    ll ans = INF;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            if (j == i) continue;
            for (int k = 0; k < c; ++k) {
                if (k == i || k == j) continue;
                ans = min(ans, gCost[0][i] + gCost[1][j] + gCost[2][k]);
            }
        }
    }
    cout << ans;
}
