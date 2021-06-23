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

int cur, cnt, pv[MX], par[MX];
set<int> conn[MX];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        conn[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        conn[a].insert(b);
    }
    
    queue<int> q;
    vector<bool> used(n);

    queue.push(0);
    used[0] = true;

    ++cnt;
    if (dfs(0) < n) {
        cout << "Confused\n\n";
        return;
    }

    val.insert(0);
    for (auto i : pos) {
        int node = i;
        while (node) {
            val.insert(node);
            node = par[node];
        }
    }

    for (auto i : val) {
        cout << i << '\n';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c; cin >> c;
    for (int i = 0; i < MX; ++i) pv[i] = -1;

    for (int i = 0; i < c; ++i) {
        solve();
    }
}
