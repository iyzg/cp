#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

bitset<1005> val;
vector<int> primes;

map<ll, ll> cnt;

void sieve() {
    val.set();
    for (int i = 2; i < 1005; i++) {
        if (val[i]) {
            primes.push_back(i);
            for (int j = i * i; j < 1005; j += i) val[j] = 0;
        }
    }   
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    sieve();
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (auto& prime : primes) {
            while (num % prime == 0) {
                cnt[prime]++;
                num /= prime;
            }
        }
        
        if (num != 1) cnt[num]++;
    }
    ll ans = 1;
    for (auto i : cnt) {
        ans = modMul(ans, i.second + 1);
    }
    cout << ans;
    return 0;
}







