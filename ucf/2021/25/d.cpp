#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

const int MX = 1e5 + 5;

int reach[MX], vis[MX];
vector<int> in[MX], out[MX];

void dfs(int v) {
    reach[v] = 1;
    for (auto u : out[v]) {
        if (!reach[u]) {
            dfs(u);
            reach[v] += reach[u];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        in[i].clear();
        out[i].clear();
        reach[i] = 0;
        vis[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        out[a].push_back(b);
        in[b].push_back(a);
    }

    set<int> valid;
    dfs(0);

    queue<int> q;
    vector<bool> used(n);

    q.push(0);
    used[0] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (reach[v] == n) val.insert(v);
        for (auto u : in[v]) {
            if (!used[u]) {
                q.push(u);
                if (reach[u] > 0) reach[u] = reach[v];
                else reach[u] = reach[v] += 1;
            }
        }
    }


    if (sz(valid)) {
        for (auto i : valid) cout << i << '\n';
    } else cout << "Confused\n";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c; cin >> c;

    for (int i = 0; i < c; ++i) {
        solve();
    }
}
