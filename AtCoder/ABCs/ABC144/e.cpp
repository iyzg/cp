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

ll N, K;
vector<ll> a, f;

bool pos(ll t) {
	ll sets = 0;
	// cout << "t: " << t << "\n";
	
	for (int i = 0; i < N; i++) {
		sets += max(0ll, (ll)ceil((double)(a[i] * f[i] - t) / (double)f[i]));
	}
	
	// cout << "sets: " << sets << "\n";
	// cout << "\n";
	return (sets <= K);
}

ll bsearch(ll l, ll r) {
	if (l == r) return l;
	if (l + 1 == r) {
		if (pos(l)) return l;
		return r;
	}
	ll m = (l + r) / 2;
	if (pos(m)) return bsearch(l, m);
	else return bsearch(m + 1, r);
}

void solve() {
    cin >> N >> K;
    a.resize(N), f.resize(N);
    for (auto& i : a) cin >> i;
    for (auto& i : f) cin >> i;
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
	cout << bsearch(0, 1e18);
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
