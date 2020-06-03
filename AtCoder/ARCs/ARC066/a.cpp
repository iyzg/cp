#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 100000;

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

ll n;
int seen[N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<ll> a(n);
	
	for (auto& i : a) {
		cin >> i;
		seen[i]++;
	}
	
	bool pos = true;
	if (n % 2) {
		if (seen[0] != 1) pos = false;
		for (int i = 2; i < n; i += 2) {
			if (seen[i] != 2) pos = false;
		}
	} else {
		for (int i = 1; i < n; i += 2) {
			if (seen[i] != 2) pos = false;
		}
	}
	
	if (!pos) cout << 0;
	else cout << modExp(2, n / 2);
    return 0;
}
