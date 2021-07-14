#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 505;

int conn[MX][MX];
int perm[MX], order[MX];
int n;

bool solve(int p) {
    if (p == n) return true;

    for (int i = 0; i < n; ++i) {
        if (p == 0 || (conn[order[p - 1]][i] && perm[i] == -1)) {
            perm[i] = p;
            order[p] = i;
            if (solve(p + 1)) return true;
            perm[i] = -1;
            order[p] = -1;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        perm[i] = -1;
        order[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> conn[i][j];
        }
    }

    solve(0);

    for (int i = 0; i < n; ++i) {
        // cout << perm[i] << ' ' << order[i] << '\n';
        cout << order[i] + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
