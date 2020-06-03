#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (auto& i : a) cin >> i;
    
    for (int i = 0; i < n - 1; ++i) {
		l[i + 1] = __gcd(l[i], a[i]);
	}
	for (int i = n - 1; i >= 1; --i) {
		r[i - 1]  = __gcd(r[i], a[i]);
	}
	
	int ans = 1;
	for (int i = 0; i < n; i++) ans = max(ans, __gcd(l[i], r[i]));
	cout << ans;
    return 0;
}
