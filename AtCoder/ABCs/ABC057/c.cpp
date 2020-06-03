#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = 10000000;

ll f(ll a, ll b) {
	int ad = 1, bd = 1;
	while (a >= 10) {
		a /= 10;
		ad++;
	}
	while (b >= 10) {
		b /= 10;
		bd++;
	}
	return max(ad, bd);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
		if (!(n % i)) {
			ans = min(ans, f(i, n / i));
		}
	}
	cout << ans;
    return 0;
}
