#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll a, b, v;

void solve() {
    cin >> a >> b >> v;
    bool allSet = true, zeroFound = false;
    for (int i = 0; i <= 31; ++i) {
        if (!(v & (1ll << i))) {
            zeroFound = true;
        } else {
            if (zeroFound) allSet = false;
        }
    }

    if (allSet) {
        cout << max(0ll, min(v, b) - a + 1) << '\n';
        return;
    }

    ll ans = 0, highest, lowest;
    for (int i = 31; i >= 0; --i) {
        if (v & (1ll << i)) {
            highest = i;
            ans = max(ans, min(b - a + 1, max((1ll << i) - a, 0ll)));
            break;
        }
    }

    int secondIndex = -1, found = 0;
    bool upTo = true;
    for (int i = 31; i >= 0; --i) {
        if (v & (1ll << i)) {
            ++found;
            if (found == 2) secondIndex = i;
        } else {
            if (found >= 2) upTo = false;
        }
    }

    ll lb = max((1ll << highest), a), ub;
    if (upTo) {
        if (found == 1) {
            ub = (1ll << highest);
        } else {
            ub = (1ll << highest + 1ll << secondIndex);
        }
    } else {
        ub = (1ll << highest) + (1ll << secondIndex) - 1;
    }

    ans = max(ans, ub - lb + 1);

    //cout << (v & -v) << '\n';
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
