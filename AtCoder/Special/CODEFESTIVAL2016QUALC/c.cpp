#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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

int n;
ll ans = 1;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), b(n), c(n, 0);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    c[0] = a[0];
    c[n - 1] = b[n - 1];

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            if (c[i] && a[i] != c[i]) {
                cout << 0;
                return 0;
            } 
            c[i] = a[i];
        }
    }
    
    for (int i = n - 2; i >= 0; --i) {
        if (b[i] > b[i + 1]) {
            if (c[i] && b[i] != c[i]) {
                cout << 0;
                return 0;
            } 
            c[i] = b[i];
        }
    }

    if (b[0] != a[n - 1]) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] < c[i] || b[i] < c[i]) {
            cout << 0;
            return 0;
        }
    }

    // for (int i = 0; i < n; ++i) cout << c[i] << ' ';
    // cout << '\n';

    for (ll i = 0, range = 0, last = 0; i < n; ++i) {
        if (c[i]) {
            if (range) {
                // cout << min(c[i], last) << ' ' << range << '\n';
                ans = modMul(ans, modExp(min(c[i], last), range));
                range = 0;
            } 
            last = c[i];
        } else ++range;
    }
    cout << ans;
}
