#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 205;

int grid[MX][MX], hgroup[MX][MX], vgroup[MX][MX];
int n, m;

int main() {
    freopen("fortmoo.in","r",stdin);
    freopen("fortmoo.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i][j] = (c == '.');
            if (!grid[i][j]) {
                hgroup[i][j] = -1;
                vgroup[i][j] = -1;
            }
        }
    }
    
    // for (int i = 0; i < n; ++i) {
        // int cur = 0;
        // for (int j = 0; j < m; ++j) {
            // if (grid[i][j]) {
                // if (j == 0 || grid[i][j - 1]) hgroup[i][j] = cur;
                // else hgroup[i][j] = ++cur;
            // }
        // }
    // }

    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (grid[j][i]) {
                if (j == 0 || grid[j - 1][i]) vgroup[j][i] = cur;
                else vgroup[j][i] = ++cur;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int len = 0; len + i < n; ++len) {
            int leftmost = -1;
            for (int j = 0; j < m; ++j) {
                if (vgroup[i][j] == -1 || vgroup[i + len][j] == -1) {
                    // reset
                    leftmost = -1;
                } else if (vgroup[i][j] != vgroup[i + len][j]){
                    continue;
                } else {
                    // calc
                    if (leftmost == -1) leftmost = j;
                    ans = max(ans, (len + 1) * (j - leftmost + 1));
                }
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < m; ++j) {
            // for (int k = i; k < n; ++k) {
                // for (int l = j; l < m; ++l) {
                    // if (hgroup[i][j] != -1 && hgroup[i][j] == hgroup[i][l] && hgroup[k][j] == hgroup[k][l] && vgroup[i][j] == vgroup[k][j] && vgroup[i][l] == vgroup[k][l]) {
                        // ans = max(ans, (l - j + 1) * (k - i + 1));
                    // }
                // }
            // }
        // }
    // }

    cout << ans;
}
