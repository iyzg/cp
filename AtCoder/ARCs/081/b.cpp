#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int n;
string s, garbage;

ll ans = 1;

// 0 if horiz, 1 if vert
int last = -1;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> garbage;
    if (n == 1 || s[0] != s[1]) {
        ans *= 3;
        last = 0;
    } else {
        ans *= 6;
        last = 1;
    }

    for (int i = last + 1; i < n; ++i) {
        if (i == n - 1 || s[i] != s[i + 1]) {
            if (!last) ans = modMul(ans, 2);
            else last = !last;
        } else {
            if (!last) {
                last = !last;
                ans = modMul(ans, 2);
            } else {
                ans = modMul(ans, 3);
            }
            i++;
        }
    }
    cout << ans;
}
    
    
