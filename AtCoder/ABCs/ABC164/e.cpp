#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 50;

ll N, M, S, U, V, A, B;
vector<pair<ll, l_l>> graph[MX];
l_l min_trade[MX];

void solve() {
    cin >> N >> M >> S;
    for (int i = 0; i < M; i++) {
		cin >> U >> V >> A >> B;
		U--; V--;
		graph[U].push_back({V, {A, B}});
		graph[V].push_back({U, {A, B}});
	}
	for (int i = 0; i < N; i++) {
		cin >> min_trade[i].first >> min_trade[i].second;
	}
	
    set<pair<int, int>> q;
    q.insert({0, 0});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T; cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
