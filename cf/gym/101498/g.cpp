 #include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
ll ans, sum, lm;

void solve() {
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto& i : a) cin >> i;

    ans = sum = 0, lm = 1;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
        lm = lm / __gcd(lm , a[i]) * a[i];
        if (!cnt.count(sum % lm)) cnt[sum % lm] = 1;
        else cnt[sum % lm]++;

        ans += cnt[sum % lm];
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
