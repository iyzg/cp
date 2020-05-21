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
const ll MX = 100005;

int N, U, V, W;
vector<i_i> graph[MX];
// 0 Black, 1 White
int color[MX];
bool used[MX];

void dfs(int v, int c) {
	used[v] = true;
	color[v] = c;
	for (auto& u : graph[v]) {
		if (!used[u.first]) {
			if (u.second % 2) dfs(u.first, !c);
			else dfs(u.first, c);
		}
	}
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
		used[i] = false;
		cin >> U >> V >> W;
		graph[U].push_back({V, W});
		graph[V].push_back({U, W});
	}
	
	dfs(1, 0);
    for (int i = 1; i <= N; i++) cout << color[i] << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
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
