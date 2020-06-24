#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w, n, sr, sc;
string s, t;

// L, R, U, D
int moves[2][4], threshold[4], lim[4];
map<char, int> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w >> n >> sr >> sc >> s >> t;
    
    m['L'] = 0;
    m['R'] = 1;
    m['U'] = 2;
    m['D'] = 3;
    
    threshold[0] = sc;
    threshold[1] = w - sc + 1;
    threshold[2] = sr;
    threshold[3] = h - sr + 1;

    for (int i = 0; i < 4; ++i) lim[i] = threshold[i];
    // cout << '\n';
    for (int i = 0; i < n; ++i) {
        int dir = m[s[i]];
        ++moves[0][dir];
        if (dir == 0) ++lim[1];
        if (dir == 1) ++lim[0];
        if (dir == 2) ++lim[3];
        if (dir == 3) ++lim[2];

        // for (int j = 0; j < 2; ++j) {
            // for (int k = 0; k < 4; ++k) {
                // cout << moves[j][k] << ' ';
            // }
            // cout << '\n';
        // }
        bool out = false;
        if (moves[0][0] - moves[1][1] >= threshold[0]) out = true;
        if (moves[0][1] - moves[1][0] >= threshold[1]) out = true;
        if (moves[0][2] - moves[1][3] >= threshold[2]) out = true;
        if (moves[0][3] - moves[1][2] >= threshold[3]) out = true;

        if (out) {
            cout << "NO";
            return 0;
        }
        dir = m[t[i]];
        if (moves[1][dir] + 1 < lim[dir])
            ++moves[1][dir];
    }
    cout << "YES";
}
