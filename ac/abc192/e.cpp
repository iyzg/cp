#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 1e5 + 5;
const ll INF = 1e18;

int n, m, x, y;

ll d[MX];

vector<pair<int, pair<ll, ll>>> graph[MX];

struct compare {
    bool operator()(const ll& a, const ll& b) {
      if (d[a] < d[b]) return true;
      else return false;
    }   
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; ++i) d[i] = INF;
    --x, --y;
    for (int i = 0; i < m; ++i) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        --a, --b;
        graph[a].push_back({b, {t, k}});
        graph[b].push_back({a, {t, k}});
    }

    vector<bool> u(n, false);

    struct compare {
        bool operator()(const ll& a, const ll& b) {
          if (d[a] < d[b]) return true;
          else return false;
        }   
    };

    d[x] = 0;
    set<ll, compare> q;
    q.insert(x);
    
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());

        for (auto edge : graph[v]) {
            ll to = edge.first;
            ll len = d[v] % edge.second.second;
            if (len != 0) {
                len = edge.second.second - len;
            }
            len += edge.second.first;

            if (d[v] + len < d[to]) {
                q.erase(to);
                d[to] = d[v] + len;
                q.insert(to);
            }
        }
        
    }

    d[y] == INF ? cout << -1 : cout << d[y];
}
