#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

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

int k;
ll ans = 1;

int facs[2005];

void comp() {
	facs[0] = facs[1] = 1;
	for (int i = 2; i <= 2000; i++) {
		facs[i] = modMul(facs[i - 1], i);
	}
}

ll combo(ll N, ll K) {
	ll res = 1;
	res = modMul(res, facs[N + K - 1]);
	res = modMul(res, modInv(facs[K]));
	res = modMul(res, modInv(facs[N - 1]));
	
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	comp();
    cin >> k;
	vector<int> a(k);
	for(auto& i : a) cin >> i;
	
	ll cur = a[0];
	for (int i = 1; i < k; i++) {
		ans = modMul(ans, combo(cur + 1, a[i] - 1));
		cur += a[i];
	}
	
    cout << ans;
    return 0;
}
