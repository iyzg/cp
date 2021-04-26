#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 998244353;

ll ans, sum;
int n;

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

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    rep(i, 1, n) {
        sum = (sum + a[i] * binpow(2, i - 1) % MOD) % MOD;
    }

    // cout << sum << endl;
    rep(i, 0, n) {
        ans = (ans + (a[i] * (sum + a[i]) % MOD)) % MOD;
        if (i < n - 1) {
            sum = (sum + MOD - a[i + 1]) % MOD;
            sum = mdiv(sum, 2);
        }
    }

    cout << ans;
}
