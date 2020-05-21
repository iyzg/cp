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
 
ll N, M;
vector<ll> a;
ll suffSum[MX];
 
// Is it possible to get v score with M pairs?
bool pos(ll v) {
	// ll orig = v;
	// cout << "v: " << v << "\n";
	ll pairs = M;
	ll avg = ceil((long double)v / pairs);
	
	int bounds[N];
	for (int i = 0; i < N; i++) bounds[i] = i + 1;
	
	while (pairs) {
		bool change = false;
		for (int i = N - 1; i >= 0; i--) {	
			if (!bounds[i] || a[i] + a[bounds[i] - 1] < avg) continue;
			if (!v || !pairs) break;
			if (bounds[i] == i + 1 && 2 * a[i] >= avg) {
				pairs--;
				v -= min(v, 2 * a[i]);
				bounds[i] = i;
				change = true;
				if (!v || !pairs) break;
				avg = ceil((long double)v / pairs);
			}
						
			// Bound is index out of pairs
			auto it = upper_bound(a.begin(), a.end(), avg - a[i] - 1);
			if (it == a.end()) continue;
 
			// # of numbers greater than needed to create avg.
			ll limit = it - a.begin();
			if (limit >= bounds[i]) continue;			
			
			change = true;
			ll index = max(limit, bounds[i] - (pairs / 2));
			ll total = suffSum[index] - suffSum[bounds[i]];
						
			v -= min(v, 2 * total);
			v -= min(v, (bounds[i] - index) * 2 * a[i]);
			pairs -= 2 * (bounds[i] - index);
			if (pairs == 1 && index > limit) {
				v -= min(v, a[index - 1] + a[i]);
				pairs--;
			}
			
			bounds[i] = index;
			if (!pairs || !v) break;
			avg = ceil((long double)v / pairs);	
		}
		if (!change) break;
	}
	
	// cout << v << "\n";
	// cout << "\n";
	return v == 0;
}
 
ll bsearch(ll l, ll r) {
	if (l == r) return r;
	if (l + 1 == r) {
		if (pos(r)) return r;
		return l;
	}
	
	ll m = (l + r) / 2;
	if (pos(m)) return bsearch(m, r);
	else return bsearch(l, m - 1);
}
 
void solve() {
    cin >> N >> M;
    a.resize(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
	suffSum[N - 1] = a[N - 1];
	for (int i = N - 2; i >= 0; --i) suffSum[i] = a[i] + suffSum[i + 1];
	// cout << "\n";
	cout << bsearch(0, 2e15);
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
