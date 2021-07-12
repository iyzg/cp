#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
const int MX = 1e5 + 5;

int n;
int a[MX];

ll binpow(ll a, ll b) {
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
    cin >> n;
    ll tot = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tot = tot * a[i] % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll combo = mdiv(tot, a[i]);
        ll adja = a[i] - 1;
/*        cout << i << ' ' << combo << ' ' << adja << '\n';
*/        ans = (ans + combo * adja % MOD) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
