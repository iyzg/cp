#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 50;

int h, w;
int white;

int grid[MX][MX];
int d[MX][MX];
bool used[MX][MX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '#');
            white += (c == '.');
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    used[0][0] = true;
    while(!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = v.first + dx[i], b = v.second + dy[i];
            if (a < 0 || a >= h || b < 0 || b >= w) continue;
            if (used[a][b] || grid[a][b]) continue;
            used[a][b] = true;
            d[a][b] = d[v.first][v.second] + 1;
            q.push({a, b});
        }
    }
    if (d[h - 1][w - 1]) cout << white - d[h - 1][w - 1] - 1;
    else cout << -1;
}
