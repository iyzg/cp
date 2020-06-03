#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll ans, sum;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    
    int r = 0;
    for (int l = 0; l < n; l++) {
		while (sum < k) {
			if (r == n) break;
			else {
				sum += a[r];
				r++;
			}
		}
		if (sum < k) break;
		ans += n - r + 1;
		sum -= a[l];
	}
	
	cout << ans;
    return 0;
}
