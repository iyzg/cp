#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve() {
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < 64; i++) {
		if ((1ll << i) <= n) {
			ans += n / (1ll << i);
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		solve();
	}
    return 0;
}
