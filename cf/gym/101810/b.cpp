#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll x, n;

void solve() {
    cin >> x >> n;
    if (n == 1) {
        cout << x << '\n';
        return;
    }

    --x;
    ll cycleLen = ((n - 1) * 2);
    ll sweeps = x / cycleLen, leftover = x % cycleLen;

    cout << sweeps + 1 << ' ';
    for (int i = 0; i < n - 2; ++i) {
        ll ans = sweeps * 2;
        if (leftover >= i + 1) ++ans;
        if (leftover >= cycleLen - 1 - i) ++ans;

        cout << ans << ' ';
    }

    if (n > 1) cout << sweeps + (leftover >= cycleLen / 2);
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
