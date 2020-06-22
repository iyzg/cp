#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

const int N = 200;

int n, m, r;
ll ans = INF;
vector<pair<ll, ll>> conn[N];
vector<ll> dist[N];

void dijkstra(int v) { 
    vector<ll> d(n, INF);
    vector<ll> u(n, false);
    d[v] = 0;
    
    for (int i = 0; i < n; ++i) {
        int c = -1;
        for (int j = 0; j < n; ++j) {
            if ((c == -1 || d[j] < d[c]) && !u[j])
                c = j;
        }
        
        // cout << v << ' ' << c << '\n';
        u[c] = true;
        for (auto edge : conn[c]) {
            ll to = edge.first, len = edge.second;
            if (d[c] + len < d[to])
                d[to] = d[c] + len;
        }
    }

    // for (int i = 0; i < n; ++i) {
        // cout << "DIST: " << v << ' ' << i << ' ' << d[i] << '\n';
    // }
    dist[v] = d;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;

    vector<int> req(r);
    for (auto& i : req) {
        cin >> i;
        --i;
    }
    sort(req.begin(), req.end());

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        conn[a].push_back({b, c});
        conn[b].push_back({a, c});
    }

    for (int i = 0; i < n; ++i) {
        dijkstra(i);
    }

    do {
        ll tmp = 0;
        for (int i = 1; i < r; ++i) {
            // cout << req[i] << ' ' << req[i - 1] << ' ' << dist[req[i]][req[i - 1]] << '\n';
            tmp += dist[req[i]][req[i - 1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(req.begin(), req.end()));
    
    cout << ans;
}
