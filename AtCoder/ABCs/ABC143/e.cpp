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
const ll MX = 305;
 
int N, M, L, A, B, C, Q, S, T;
vector<l_l> graph[MX];
 
vector<ll> refills[MX], gas[MX];
void dijkstra(int s,vector<ll> &r, vector<ll> &g) {
	r.assign(MX, INF);
	g.assign(MX, -1);
	vector<bool> u(N, false);
	
    r[s] = 0;
    g[s] = L;
    for (int i = 0; i < N; i++) {
        int v = -1;
        for (int j = 1; j <= N; j++) {
            if (!u[j]) {
				if (v == -1) v = j;
				else if (r[j] < r[v]) v = j;
				else if (r[j] == r[v] && g[j] > g[v]) v = j;
			}
        }
		
        if (r[v] == INF)
            break;
 
        u[v] = true;
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;
			
			if (g[v] < len) {
				if (r[v] + 1 < r[to] || (r[v] + 1 == r[to] && L - len > g[to])) {
					r[to] = r[v] + 1;
					g[to] = L - len;
				}
			} else {
				if (r[v] < r[to] || (r[v] == r[to] && g[v] - len > g[to])) {
					r[to] = r[v];
					g[to] = g[v] - len;
				}
			}
        }	
	}
}
 
void solve() {
    cin >> N >> M >> L;
    
    for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		if (C > L) continue;
		graph[A].push_back({B, C});
		graph[B].push_back({A, C});
	}
	
	for (int i = 1; i <= N; i++) {
		dijkstra(i, refills[i], gas[i]);
	}
	
	cin >> Q;
	// DJIKSTRA
	while (Q--) {
		cin >> S >> T;
		refills[S][T] == INF ? cout << "-1\n" : cout << refills[S][T] << "\n";
	}
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll testCases = 1; // cin >> testCases;
    while (testCases--) solve();
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
