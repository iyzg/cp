#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

void solve() {
	cin >> a >> b;
	ll as = 0, bs = 0;
	while (!(a & (1ll << 0))) {
		a = a >> 1;
		as++;
	}
	
	while (!(b & (1ll << 0))) {
		b = b >> 1;
		bs++;
	}
	
	if (a != b) {
		cout << -1 << "\n";
		return;
	}
	
	ll diff = abs(bs - as);
	// cout << "diff " << diff << "\n";
	ll ans = 0;
	while (diff >= 3) {
		diff -= 3;
		ans++;
	}
	while (diff >= 2) {
		diff -= 2;
		ans++;
	}
	while (diff >= 1) {
		diff--;
		ans++;
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
