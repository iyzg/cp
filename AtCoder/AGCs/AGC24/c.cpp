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

int N;

void solve() {
    cin >> N;
    vector<ll> a(N);
    ll ans = 0;
    for (auto& i : a) cin >> i;
    for (int i = N - 1; i >= 0; --i) {
		if (a[i] > i) {
			cout << -1;
			return;
		}
		
		ans += a[i];
		// cout << "Adding " << a[i] << " " << i << "\n";
		ll dist = a[i];
		int o = i;
		for (int j = 1; j < dist && o - j >= 0; j++) {
			if (a[o - j] + 1 == a[o - j + 1]) {
				// cout << "hi";
				--i;
			} else if (a[o - j] >= a[o - j + 1]) {
				break;
			} else {
				cout << -1;
				return;
			}
		}
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
