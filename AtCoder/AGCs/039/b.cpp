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
const ll MX = 205;

int N;
vector<int> graph[MX];
ll ans = -INF;

bool valid;
ll groups;
int sets[MX];

void color(int start) {
	valid = true;
	groups = 1;
	for (int j = 0; j < N; j++) sets[j] = -1;
	
	queue<int> q;
	q.push(start);
	sets[start] = 1;
	
	while (!q.empty() && valid) {
		int v = q.front();
		q.pop();
		
		for (auto u : graph[v]) {
			// cout << v << " " << u << "\n";
			if (sets[u] == -1) {
				sets[u] = sets[v] + 1;
				chmax(groups, (ll)sets[u]);
				q.push(u);
			} else {
				if (sets[v] - sets[u] > 1 || sets[u] == sets[v]) {
					valid = false;
					break;
				}
			}
		}
	}
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			if (S[j] == '1') graph[i].push_back(j);
		}
	}
	
	for (int i = 0; i < N; i++) {
		color(i);
		
		if (valid) {
			chmax(ans, groups);
		}
	}
	
	ans == -INF ? cout << -1 : cout << ans;
	
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
