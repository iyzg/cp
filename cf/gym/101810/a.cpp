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

const int MX = 1e5 + 5;

struct node {
    ll l, r, v;
    
    bool operator < (const node &n) const {
        return l < n.l;
    }
};


ll m, k, ps[MX];
node a[MX];

bool valid(int index, ll val) {
    if (a[index].r <= val || (a[index].l <= val && a[index].r >= val)) return true;
    return false;
}

int bsearch(ll lo, ll hi, ll val) {
    if (lo == hi) return hi;
    if (hi - lo == 1) {
        if (valid(hi, val)) return hi;
        return lo;
    }
    int m = (hi + lo) / 2;
    if (valid(m, val)) return bsearch(m, hi, val);
    else return bsearch(lo, m - 1, val);
}

void solve() {
    cin >> m >> k;
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].v;
    }

    a[0].l = -1, a[0].r = -1, a[0].v = 0;
    ps[0] = 0;

    sort(a + 1, a + m + 1);

    for (int i = 1; i <= m; ++i) {
        ps[i] = (a[i].r - a[i].l + 1) * a[i].v + ps[i - 1];
    }

    for (int i = 1; i <= m; ++i) {
        ll lb = max((ll)0, a[i].r - k + 1), ub = min((ll)1e9, a[i].l + k - 1);
        int sv = bsearch(0, m, ub);
        int ev = bsearch(0, m, lb);

        if (ub > a[sv].r) {
            ans = max(ans, ps[sv] - ps[i - 1]);
        } else {
            ans = max(ans, ps[sv] - ps[i - 1] - (a[sv].r - ub) * a[sv].v);
        }

        if (lb > a[ev].r) {
            ans = max(ans, ps[i] - ps[ev]);
        } else {
            ans = max(ans, ps[i] - ps[ev - 1] - (lb - a[ev].l) * a[ev].v);
        }
/*        cout << i << ' ' << sv << ' ' << ev << '\n';
*/    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
