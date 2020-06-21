#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 13;
const ll FMOD = 1e9 + 7;
 
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
 
string s;
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    reverse(s.begin(), s.end());
    map<ll, ll> cnts;
    
    ll cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != '?') {
            cur += modMul(modExp(10, i), (s[i] - '0')); cur %= MOD;
        } else {
            if (cnts.empty()) {
                for (int digit = 0; digit < 10; ++digit) {
                    ll tmp = modMul(modExp(10, i), digit); tmp %= MOD;
                    
                    ++cnts[tmp];
                }
            } else {
                ll toAdd[13] = { 0 };
                for (int digit = 0; digit < 10; ++digit) {
                    ll tmp = modMul(modExp(10, i), digit); tmp %= MOD;
                    
                    if (tmp) {
                        for (auto i : cnts) 
                            toAdd[(i.first + tmp) % 13] += i.second;
                    }
                }
                for (int j = 0; j < 13; ++j) 
                    cnts[j] = (cnts[j] + toAdd[j]) % FMOD;
            }
        }
    }
 
    // Don't just use cnts[5], use whatever is correct for what cur is
    // ll tot = 1;
    // for (auto i : cnts) {
        // cout << i.first << ' ' << i.second % FMOD << '\n';
        // tot *= i.second;
    // }
    ll fin;
    if (cur <= 5) fin = 5 - cur;
    else {
        fin = 13 - cur + 5;
    }
    if (cur == 5) cout << max(1ll, cnts[fin]);
    else cout << cnts[fin] % FMOD;
}
