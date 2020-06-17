#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n, q, k;
vector<pair<ll, ll>> conn[N];

ll dist[N];

void dfs(int v, int p) {
    for (auto& u : conn[v]) {
        if (u.first != p) {
            dist[u.first] = dist[v] + u.second;
            dfs(u.first, v);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        conn[a].push_back({b, c});
        conn[b].push_back({a, c});
    }

    cin >> q >> k;
    --k;
    dfs(k, -1);
    
    for (int qi = 0; qi < q; qi++) {
        int i, j;
        cin >> i >> j;
        --i; --j;
        cout << dist[i] + dist[j] << '\n';
    }
}

