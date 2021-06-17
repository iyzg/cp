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

const int MX = 5 * 1e4 + 5;

int n, k, l;
vector<int> graph[MX];

int timer = 0;
vector<int> tin, tout;
vector<vector<int>> up;
stack<int> s;

void dfs(int v, int p) {
    tin[v] = ++timer;
    s.push(v);
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : graph[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }

    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int score[MX], scin[MX], scout[MX];

int main() {
    setIO("maxflow");
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    tin.resize(n), tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(0, 0);

    while (k--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++scin[a], ++scin[b];
        int cp = lca(a, b);
        if (cp == a || cp == b) {
            --scin[cp];
            --scout[cp];
        } else {
            --scin[cp];
            --scout[cp];
        }
    }

    int cmax = -MX;
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        score[v] += scin[v];
        cmax = max(cmax, score[v]);
        score[v] += scout[v];
        score[up[v][0]] += score[v];
    }

    cout << cmax;
}
