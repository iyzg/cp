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

ll N, D, A;

void solve() {
    cin >> N >> D >> A;
    vector<l_l> a(N);
    for (auto& i : a) {
		cin >> i.first >> i.second;
		i.second = ceil(i.second / (double)A);
	}
    sort(a.begin(), a.end());
    ll dp[N + 5] = { 0 };
    ll change = 0, ans = 0;
	int r = 0;
    for (int i = 0; i < N; i++) {
		if (a[i].second + change > 0) {
			while (r < N && a[r].first - a[i].first <= 2 * D) r++;
			r--;
			ans += (a[i].second + change);
			dp[r] += (a[i].second + change);
			change -= (a[i].second + change);
		}
		change += dp[i];
	}
	cout << ans;
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
