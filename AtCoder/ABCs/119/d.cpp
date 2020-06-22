#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int a, b, q;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> q;
    set<ll> s, t;
    for (int i = 0; i < a; ++i) {
        ll si; cin >> si;
        s.insert(si);
    }

    for (int i = 0; i < b; ++i) {
        ll ti; cin >> ti;
        t.insert(ti);
    }

    for (int i = 0; i < q; ++i) {
        // Find next temple and shrine on both sides
        ll x; cin >> x;
        ll es, et, ws, wt;

        // Use upper bound to find first on the east side
        auto sit = s.upper_bound(x), tit = t.upper_bound(x);
        if (sit == s.end())
            es = INF;
        else
            es = *sit;

        if (tit == t.end())
            et = INF;
        else
            et = *tit;
        
        if (sit != s.begin()) {
            sit--;
            ws = *sit;
        } else ws = -INF;

        if (tit != t.begin()) {
            tit--;
            wt = *tit;
        } else wt = -INF;

        ll ans = INF;
        // cout << ws << ' ' << wt << ' ' << es << ' ' << et << '\n';
        ans = min(ans, max(es, et) - x);
        ans = min(ans, x - min(ws, wt));

        ll lft = x - wt, rht = es - x;
        if (lft > rht) swap(lft, rht);
        ans = min(ans, lft * 2 + rht);

        lft = x - ws, rht = et - x;
        if (lft > rht) swap(lft, rht);
        ans = min(ans, lft * 2 + rht);

        cout << ans << '\n';
    }
}
