#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 100;

int h, w;
int grid[MX][MX];
int transitions[MX][MX];
bool used[MX][MX];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0 ; j < w; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '#');
        }
    }
 
    queue<pair<int, int>> q;
    q.push({0, 0});
    transitions[0][0] = grid[0][0];
    used[0][0] = true;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int a = v.first + dx[i], b = v.second + dy[i];
            if (a < 0 || a >= h || b < 0 || b >= w) continue;
            if (used[a][b]) {
                int ch = transitions[v.first][v.second] + (!grid[v.first][v.second] && grid[a][b]);
                transitions[a][b] = min(transitions[a][b], ch);
            } else {
                q.push({a, b});
                used[a][b] = true;
                transitions[a][b] = transitions[v.first][v.second] + (!grid[v.first][v.second] && grid[a][b]);
            }
        }
    }
    
    // for (int i = 0; i < h; i++) {
        // for (int j = 0; j < w; j++) {
            // cout << transitions[i][j] << ' ';
        // }
        // cout << '\n';
    // }
    
    cout << transitions[h - 1][w - 1];
}
