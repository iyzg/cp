#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 5005;

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

int n, k;

ll fac[N], inv[N];

void pre() {
    fac[1] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac[i] = modMul(fac[i - 1], i);
        inv[i] = modInv(fac[i]);
    }
}

ll combo(int n, int k) {
    ll t = fac[n + k - 1];
    ll b = modMul(inv[k], inv[n - 1]);
    return max(modMul(t, b), 1ll);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    pre();
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        if (n - k - (i - 1) < 0) cout << 0 << '\n';
        else cout << modMul(combo(i, k - i), combo(i + 1, n - k - (i - 1))) << '\n';
    }
}
    
