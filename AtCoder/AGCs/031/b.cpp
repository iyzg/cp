#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll N = 200005;

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

bitset<N> last;
ll prob[N], pos[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int ci; cin >> ci;
        if (!i || ci != a[a.size() - 1])
            a.push_back(ci);
    }

    for (int i = 1; i < N; ++i) prob[i] = 1;
    n = a.size();
    pos[n] = 1;

    last.set();
    bool pair = false;
    for (int i = n - 1; i >= 0; --i) {
        if (last[a[i]]) {
            prob[a[i]] = pos[i + 1];
            pos[i] = pos[i + 1];
            last[a[i]] = 0;
        } else {
            ans = modAdd(ans, prob[a[i]]);
            // cout << i << ' ' << prob[a[i]] << '\n';
            prob[a[i]] = modAdd(prob[a[i]], pos[i + 1]);
            pos[i] = prob[a[i]];
    
            // if (!pair) {
                // pos[i] = 2;
                // pair = true;
            // } else pos[i] = pos[i + 1];
        }
    }

    // for (int i = 0; i < n; i++) {
        // cout << i << ' ' << pos[i] << ' ' << prob[a[i]] << '\n';
    // }
    cout << ans;
}
