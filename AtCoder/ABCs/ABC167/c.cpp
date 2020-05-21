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
const ll MX = 1000001;

int N, M, X;
int books[12][13];
ll ans = INF;

void solve() {
    cin >> N >> M >> X;
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M + 1; j++) {
			cin >> books[i][j];
		}
	}
    
    for (int i = 0; i < (1ll << N); i++) {
		vector<ll> skills(M, 0);
		ll cost = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cost += books[j][0];
				for (int k = 1; k < M + 1; k++) skills[k - 1] += books[j][k];
			}
		}	
		
		// cout << cost << "\n";
		bool pos = true;
		for (int j = 0; j < M; j++) {
			if (skills[j] < X) {
				// cout << "broke on " << j << "\n";
				pos = false;
				break;
			}
		}
		if (pos) chmin(ans, cost);
	}
    
    if (ans == INF) cout << -1;
    else cout << ans;
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
