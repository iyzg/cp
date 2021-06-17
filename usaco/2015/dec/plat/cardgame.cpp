#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct segtree {
    int size;
    // # of cards that can be covered, that can cover, and points
    vector<int> coverable, covers, points;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;

        coverable.assign(2 * size, 0);
        covers.assign(2 * size, 0);
        points.assign(2 * size, 0);
    }

    void set(int i, int mode, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (mode == 0) coverable[x] = 1;
            else covers[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, mode, 2 * x + 1, lx, m);
        } else {
            set(i, mode, 2 * x + 2, m, rx);
        }

        int ep = min(coverable[2 * x + 1], covers[2 * x + 2]);

        coverable[x] = coverable[2 * x + 1] + coverable[2 * x + 2] - ep;
        covers[x] = covers[2 * x + 1] + covers[2 * x + 2] - ep;
        points[x] = points[2 * x + 1] + points[2 * x + 2] + ep;
    }

    void set(int i, int mode) {
        set(i, mode, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) {
            return points[x];
        }

        int m = (lx + rx) / 2;
        ll p1 = query(l, r, 2 * x + 1, lx, m);
        ll p2 = query(l, r, 2 * x + 2, m, rx);
        return p1 + p2;
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

};

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    int n;

    cin >> n;
    vector<bool> used(2 * n);
    vector<int> a(n), b;
    for (auto& i : a) {
        cin >> i;
        --i;
        used[i] = true;
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            b.push_back(i);
        }
    }
    reverse(all(b));

    segtree st0, st1;
    st0.init(2 * n), st1.init(2 * n);
    vector<int> r0(n + 1), r1(n + 1);
    for (int i = 0; i < n; ++i) {
        st0.set(a[i], 0);
        st0.set(b[i], 1);
        r0[i + 1] = st0.points[0];
    }
    
    reverse(all(a));
    reverse(all(b));
    for (int i = 0; i < n; ++i) {
        a[i] = 2 * n - 1 - a[i];
        b[i] = 2 * n - 1 - b[i];
    }

    for (int i = 0; i < n; ++i) {
        st1.set(a[i], 0);
        st1.set(b[i], 1);
        r1[i + 1] = st1.points[0];
    }
    
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, r0[i] + r1[n - i]);
    }

    cout << ans;
}
