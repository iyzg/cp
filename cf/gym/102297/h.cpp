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

const int INF = 1e9 + 7;

int tc = 1, r, c;
bool image[9][9], canMark[9][9];

int dp[9 * 9 + 1][(1 << 18)];

void solve() {
    cin >> r >> c;

    int stampMask = (1 | (1 << (c - 1)) | (1 << c) | (1 << (c + 1)) | (1 << (2 * c)));

    for (int i = 0; i < r; ++i) {
        string s; cin >> s;
        for (int j = 0; j < c; ++j) {
            image[i][j] = (s[j] == '#');
            canMark[i][j] = false;
        }
    }

    for (int i = 1; i < r - 1; ++i) {
        for (int j = 1; j < c - 1; ++j) {
            if (image[i][j] && image[i - 1][j] && image[i][j - 1] && image[i][j + 1] && image[i + 1][j]) canMark[i - 1][j] = true;
        }
    }

    for (int i = 0; i <= 9 * 9; ++i) {
        for (int j = 0; j < (1 << 18); ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    int curCell = -1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ++curCell;
            int nxtCell = curCell + 1;

            for (int mask = 0; mask < (1 << (2 * c)); ++mask) {
                if (dp[curCell][mask] < INF) {
                    if (canMark[i][j]) {
                        int nxtMask = (mask | stampMask) >> 1;
                        // printf("%d, %d - %d, %d, %d\n", i, j, mask, stampMask, nxtMask);
                        dp[nxtCell][nxtMask] = min(dp[nxtCell][nxtMask], 1 + dp[curCell][mask]);

                        // Mark
                    }

                    // Don't mark
                    if (!image[i][j] || (mask & 1)) {
                        int nxtMask = mask >> 1;
                        dp[nxtCell][nxtMask] = min(dp[nxtCell][nxtMask], dp[curCell][mask]);
                    }
                }
            }
        }
    }

    string res = "impossible";
    if (dp[r * c][0] < INF) {
        res = to_string(dp[r * c][0]);
    }

    printf("Image #%d: %s\n\n", tc, res.c_str());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; tc <= t; ++tc) {
        solve();
    }
}
