#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int te = 1;
int c;
set<char> shapes[3][3], flavors[3][3];

void solve() {
    cin >> c;
    // Reset
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            shapes[i][j].insert('S');
            shapes[i][j].insert('R');
            shapes[i][j].insert('T');
            flavors[i][j].insert('S');
            flavors[i][j].insert('V');
            flavors[i][j].insert('C');
        }
    }

    for (int i = 0; i < c; ++i) {
        int x, y; cin >> x >> y;
        vector<pair<int, int>> val;
        for (int tx = 0; tx < 3; ++tx) {
            for (int ty = 0; ty < 3; ++ty) {
                if (tx + x <= 3 && ty + y <= 3) {
                    val.push_back({tx, ty});
                }
            }
        }

        for (int cx = 0; cx < x; ++cx) {
            for (int cy = 0; cy < y; ++cy) {
                string clue; cin >> clue;

                for (auto p : val) {
                    int nx = p.first + cx, ny = p.second + cy;
                    if (clue[0] != '_') {
                        auto it = shapes[nx][ny].begin();
                        while (it != shapes[nx][ny].end()) {
                            auto nxt = next(it);
                            if (*it != clue[0]) shapes[nx][ny].erase(it);

                            it = nxt;
                        }
                    }

                    if (clue[1] != '_') {
                        auto it = flavors[nx][ny].begin();
                        while (it != flavors[nx][ny].end()) {
                            auto nxt = next(it);
                            if (*it != clue[1]) flavors[nx][ny].erase(it);

                            it = nxt;
                        }

                    }
                }
            }
        }
    }

    cout << "Puzzle #" << te << ": \n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // cout << *shapes[i][j].begin() << *flavors[i][j].begin() << ' ';
            for (auto x : shapes[i][j]) cout << x;
            cout << ',';
            for (auto x : flavors[i][j]) cout << x;
            cout << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; te <= t; ++te) {
        solve();
    }
}
