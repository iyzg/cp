#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll npot[64], ppot[64];
bitset<64> ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for (int i = 0; i <= 50; ++i) {
		if (i % 2) {
			npot[i] = -(1ll << i);
			if (i > 2) npot[i] += npot[i - 2];
		} else {
			ppot[i] = (1ll << i);
			if (i > 1) ppot[i] += ppot[i - 2];
		}
	}
	
	if (!n) {
		cout << 0;
		return 0;
	}
	
	ll cur;
	if (n > 0) {
		int pow;
		for (int i = 0; i < 64; i++) {
			if (ppot[i] >= n) {
				pow = i;
				break;
			}
		} 
		cur = (1ll << pow);
		ans[pow] = 1;
	} else {
		int pow;
		for (int i = 0; i < 64; i++) {
			if (npot[i] <= n) {
				pow = i;
				break;
			}
		} 
		cur = -(1ll << pow);
		ans[pow] = 1;
	}
	
	ll target = n - cur;
	// sorta bsearch
	for (int i = 60; i > 0; --i) {
		ll change = (1ll << i);
		if (i % 2) change *= -1;
		
		if ((change < 0 && target > 0) || (change > 0 && target < 0)) continue;
		
		if (change < 0) {
			if (cur + change + ppot[i - 1] < n) continue;
			else {
				ans[i] = 1;
				cur += change;
			}
		} else {
			if (cur + change + npot[i - 1] > n) continue;
			else {
				ans[i] = 1;
				cur += change;
			}
		}
		target = n - cur;
	}
	if (cur != n) ans[0] = 1;
	
	
	bool found = false;
	for (int i = 63; i >= 0; --i) {
		if (found || ans[i]) {
			if (ans[i]) {
				cout << 1;
				found = true;
			} else cout << 0;
		}
	}
	
    return 0;
}
