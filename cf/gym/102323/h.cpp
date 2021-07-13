#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int te = 1, c;

vector<string> pos = { "RC", "RS", "RV" ,"SC", "SS", "SV", "TC", "TS", "TV" };
bool used[9];
vector<vector<vector<string>>> clues;
string board[3][3];

bool solve(int row, int col) {
    if (row == 3) {
        for (auto clue : clues) {
            bool fitClue = false;
            for (int bx = 0; bx < 3; ++bx) {
                for (int by = 0; by < 3; ++by) {
                    if (bx + sz(clue) > 3 || by + sz(clue[0]) > 3) continue;

                    fitClue = true;
                    for (int cx = 0; cx < sz(clue); ++cx) {
                        for (int cy = 0; cy < sz(clue[0]); ++cy) {
                            if (clue[cx][cy][0] != '_' && clue[cx][cy][0] != board[bx + cx][by + cy][0]) fitClue = false;
                            if (clue[cx][cy][1] != '_' && clue[cx][cy][1] != board[bx + cx][by + cy][1]) fitClue = false;
                        }
                    }
                    if (fitClue) break;
                }
                if (fitClue) break;
            }

            if (!fitClue) {
                return false;
            }
        }
        return true;
    }

    for (int i = 0; i < 9; ++i) {
        if (!used[i]) {
            used[i] = true;
            board[row][col] = pos[i];
            bool res = solve((3 * row + col + 1) / 3, (col + 1) % 3);
            if (res) return true;
            used[i] = false;
        }
    }

    return false;
}

void solve() {
    cin >> c;

    clues.clear();
    for (int i = 0; i < c; ++i) {
        int x, y; cin >> x >> y;
        vector<vector<string>> clue(x, vector<string>(y));
        for (int cx = 0; cx < x; ++cx) {
            for (int cy = 0; cy < y; ++cy) {
                cin >> clue[cx][cy];
            }
        }

        clues.push_back(clue);
    }

    solve(0, 0);

    int cnt = 0;
    for (auto clue : clues) {
        ++cnt;
        bool fitClue = false;
        for (int bx = 0; bx < 3; ++bx) {
            for (int by = 0; by < 3; ++by) {
                if (bx + sz(clue) > 3 || by + sz(clue[0]) > 3) {
                    fitClue = false;
                    continue;
                }
                fitClue = true;
                for (int cx = 0; cx < sz(clue); ++cx) {
                    for (int cy = 0; cy < sz(clue[0]); ++cy) {
                        if (clue[cx][cy][0] != '_' && clue[cx][cy][0] != board[bx + cx][by + cy][0]) fitClue = false;
                        if (clue[cx][cy][1] != '_' && clue[cx][cy][1] != board[bx + cx][by + cy][1]) fitClue = false;
                    }
                }
                if (fitClue) {
                    cout << "Clue #" << cnt << " worked on " << bx << ", " << by << '\n';
                    break;
                }
            }
            if (fitClue) break;
        }
    }

    cout << "Puzzle #" << te << ": \n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
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
