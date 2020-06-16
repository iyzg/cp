#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, x;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> x;
    ll d = a % x;
    if (d) a += (x - d);
    if (a > b) {
		cout << 0;
		return 0;
	}
	
    ll ans = 1;
    ans += (b - a) / x;
    cout << ans;
    return 0;
}
