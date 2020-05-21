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
const ll MX = 1005;

int N, M, B, C;
int cost[MX];
vector<ll> boxes[MX];
ll ans = INF;

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
		cin >> cost[i] >> B;
		for (int j = 0; j < B; j++) {
			cin >> C;
			boxes[i].push_back(C);
		}
	}
	
	set<int> keys;
	for (int i = 0; i < (1 << M); i++) {
		ll tmp = 0;
		cout << "i : " << i << "\n";
		for (int j = 0; j < M; j++) {
			if (i & (1 << j)) {
				cout << "Using key " << j << "\n";
				tmp += cost[j];
				for (auto box : boxes[j]) keys.insert(box);
			}
		}
		cout << "\n";
		if ((int)keys.size() == N) {
			chmin(ans, tmp);
		}
		keys.clear();
	}
	
	ans == INF ? cout << -1 : cout << ans;
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
