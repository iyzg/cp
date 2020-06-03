#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MX = 100005;

namespace Modop {
    ll modAdd(ll a, ll b) {
        return (a + b) % MOD;
    }
    
    ll modSub(ll a, ll b) {
        return (((a - b) % MOD) + MOD) % MOD;
    }
    
    ll modMul(ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    ll modExp(ll base, ll power) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % MOD;
            return cur;
        }
    }
    
    ll modInv(ll a) {
        return modExp(a, MOD - 2);
    }
    
    ll modDiv(ll a, ll b) {
        return modMul(a, modInv(b));
    }
}

using namespace Modop;

int N;

ll ans = 1;
ll fac[MX];

void comp() {
	fac[0] = fac[1] = 1;
	for (int i = 2; i < MX; i++) {
		fac[i] = modMul(fac[i - 1], i);
	}
}

ll combo(ll n, ll k) {
	ll re = 1;
	re = modMul(re, fac[n + k - 1]);
	re = modMul(re, modInv(fac[k]));
	re = modMul(re, modInv(fac[n - 1]));
	return re;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	comp();
    cin >> N;
    vector<int> a(N);
    map<int, int> cnt;
    for (auto& i : a) {
		cin >> i;
		cnt[i]++;
	}
    
    // Make sure vertex 1 is the root
    if (a[0] || cnt[0] > 1) {
		cout << 0;
		return 0;
	}
	
	int lastd = 0, lastc = 1;
	for (auto& i : cnt) {
		if (i.first == 0) continue;
		if (i.first - 1 != lastd) {
			cout << 0;
			return 0;
		} else {
			// cout << lastc << " " << i.second << " " << combo(lastc, i.second) << "\n";
			ans = modMul(ans, modExp(lastc, i.second));
		}
		lastd = i.first;
		lastc = i.second;
	}
	cout << ans;
    return 0;
}
