#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300000;

int n, m;
vector<int> conn[N];
bitset<N> vis, depth;

vector<int> ans;

void bfs(int i) {
    vis[i] = true;
    queue<int> q;
    stack<int> st;
    q.push(i);
    st.push(i);
    vector<int> even, odd;
    even.push_back(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // cout << i << ' ' << v << '\n';
        for (auto u : conn[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                st.push(u);
            }
        }
    }




    if (even.size() < odd.size())
        ans.insert(ans.end(), even.begin(), even.end());
    else 
        ans.insert(ans.end(), odd.begin(), odd.end());
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) conn[i].clear();
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        conn[x].push_back(y);
    }

    ans.clear();
    vis.reset();
    depth.reset();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) bfs(i);
    }
    cout << ans.size() << '\n';
    if (ans.size()) {
        for (auto i : ans) cout << i + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
