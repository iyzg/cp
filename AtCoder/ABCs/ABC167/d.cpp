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
const ll MX = 200005;

ll N, K;
vector<ll> a, cycle;
bitset<MX> vis;

void solve() {
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i]--;
	}
	
    vis.reset();
    ll cur = 0, cnt = 0;
    while (!vis[cur]) {
		if (cnt == K) {
			cout << cur + 1;
			return;
		}
		vis[cur] = 1;
		cur = a[cur];
		cnt++;
	}
	
	vis.reset();
	while (!vis[cur]) {
		if (cnt == K) {
			cout << cur + 1;
			return;
		}
		cycle.push_back(cur);
		vis[cur] = 1;
		cur = a[cur];
		cnt++;
	}
	
	K -= cnt;
    
    // cout << cycle.size() << "\n";
    cout << cycle[K % cycle.size()] + 1;
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
