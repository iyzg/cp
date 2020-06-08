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
string s;

map<char, int> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    
    for (auto& i : s) {
        m[i]++;
    }

    ll ans = 1;
    for (auto& i : m) {
        ans = modMul(ans, i.second + 1);
    }
    ans--;
    cout << ans;
}
