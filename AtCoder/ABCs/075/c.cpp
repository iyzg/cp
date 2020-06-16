#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50;

int n, m;
// to, edge id
vector<pair<int, int>> conn[N];

bitset<N> vis;

void dfs(int v, int id) {
    vis[v] = true;
    for (auto& u : conn[v]) {
        if (!vis[u.first] && u.second != id) dfs(u.first, id);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        conn[a].push_back({b, i});
        conn[b].push_back({a, i});
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vis.reset();
        dfs(0, i);
        
        bool bridge = false;
        for (int j = 0; j < n; j++) {
            if (!vis[j]) bridge = true;
        }
        if (bridge) ans++;
    }
    cout << ans;
}

