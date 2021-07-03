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

const int MX = 1e5 + 5;

int n, q, l;
ll sum;
vector<pair<int, int>> conn[MX];
ll ddown[MX], dup[MX];

int timer, tin[MX], tout[MX];
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : conn[v]) {
        if (u.first == p) {
            dup[v] = dup[p] + u.second;
        }
    }
    for (auto u : conn[v]) {
        if (u.first != p) {
            // cout << v << " -> " << u.first << ' ' << ddown[v] << ' ' << u.second << ' ' << ddown[u.first] << '\n';
            ddown[u.first] = ddown[v] + u.second;
            dfs(u.first, v);
        } 
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}


void solve() {
    cin >> n;
    sum = 0;
    timer = 0;
    ddown[0] = dup[0] = 0;
    for (int i = 0; i < n; ++i) {
        conn[i].clear();
    }

    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    for (int i = 0; i < n - 1; ++i) {
        ll u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        --u, --v;
        conn[u].push_back({v, c1});
        conn[v].push_back({u, c2});
        sum += c1 + c2;
    }
    
    dfs(0, 0);

    // for (int i = 0; i < n; ++i) {
        // cout << ddown[i] << ' ' << dup[i] << '\n';
    // }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        int ca = lca(x, y);
        if (ca == x) {
            cout << sum - (dup[y] - dup[x]);
        } else if (ca == y) {
            cout << sum - (ddown[x] - ddown[y]);
        } else {
            cout << sum - (ddown[x] - ddown[ca]) - (dup[y] - dup[ca]);
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
