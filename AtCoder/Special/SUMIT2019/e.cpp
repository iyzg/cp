#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const int N = 100005;

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

int n, zc;
ll cc[N], mul[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < N; i++) mul[i] = 1;

    for (int i = 0; i < n; i++) {
        if (!a[i]) zc++;
        else {
            mul[a[i]] *= cc[a[i] - 1];
            cc[a[i] - 1]--;
        }
        cc[a[i]]++;
    }

    ll ans = 1;
    for (int i = 1; i < n; i++) {
        ans = modMul(ans, mul[i]);
    }

    if (zc == 1) ans = modMul(ans, 3ll);
    else if (zc == 2 || zc == 3) ans = modMul(ans, 6ll);
    else ans = 0;
    cout << ans;
}
