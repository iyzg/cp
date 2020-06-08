#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), psum(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
	psum[0] = a[0];
	for (int i = 1; i < n; i++) {
		psum[i] = a[i] + psum[i - 1];
	}
	
	ans = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		if (psum[i] * 2 >= a[i + 1]) ans = i;
		else break;
	}
	cout << n - ans;
    return 0;
}
