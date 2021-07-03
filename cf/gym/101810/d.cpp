#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, m;

void solve() {
    cin >> n >> m;
    ll ans = 0;
    if (n % 2) ans = (n / 2 + 1) * m;
    else {
        ans += n / 2 * ceil((long double)m / 2);
        ans += m / 2 * (n / 2 + 1);
    }
    swap(n, m);
    if (n % 2) ans = min(ans, (n / 2 + 1) * m);
    else {
        ll temp = 0;
        temp += n / 2 * ceil((long double)m / 2);
        temp += m / 2 * (n / 2 + 1);
        ans = min(ans, temp);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
