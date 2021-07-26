#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
const ll MX = 2 * 1e5 + 9;

ll a, b;
ll fact[MX];

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll mdiv(ll a, ll b) {
    return a * binpow(b, MOD - 2) % MOD;
}

void solve() {
    cin >> a >> b;
    ll lo = a - (b + 1);
    cout << 2 * mdiv(fact[lo + b], fact[lo] * fact[b] % MOD) % MOD << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < MX; ++i) {
        fact[i] = i * fact[i - 1] % MOD;
    }

    int t; cin >> t;
    while (t--) 
        solve();
}
