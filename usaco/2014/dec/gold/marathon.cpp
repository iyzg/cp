#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

const ll INF = 1e18;
const int MX = 1e5 + 5;

struct maxSegtree {
    int size;
    vector<ll> maxs;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        maxs.assign(2 * size, 0ll);
    }
    
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                maxs[x] = a[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            maxs[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        maxs[x] = max(maxs[2 * x + 1], maxs[2 * x + 2]);
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return -INF;
        if (lx >= l && rx <= r) return maxs[x];

        int m = (lx + rx) / 2;
        ll m1 = query(l, r, 2 * x + 1, lx, m);
        ll m2 = query(l, r, 2 * x + 2, m, rx);
        return max(m1, m2);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

struct sumSegtree {
    int size;
    vector<ll> sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
    }
    
    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                sums[x] = a[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];

        int m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int x[MX], y[MX];

int n, q;

int dist(int p1, int p2) {
    return abs(x[p2] - x[p1]) + abs(y[p2] - y[p1]);
}

int main() {
    setIO("marathon");
    cin >> n >> q;
    sumSegtree sst;
    maxSegtree mst;
    sst.init(n), mst.init(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<int> saved(n);
    vector<int> distToRight(n, 0);

    saved[0] = saved[n - 1] = 0;
    for (int i = 1; i < n - 1; ++i) {
        saved[i] = dist(i + 1, i) + dist(i, i - 1) - dist(i + 1, i - 1);
    }
    for (int i = 0; i < n - 1; ++i) {
        distToRight[i] = dist(i + 1, i);
    }
    
    mst.build(saved);
    sst.build(distToRight);
    
    while (q--) {
        char op;
        cin >> op;
        if (op == 'U') {
            int qi, qx, qy;
            cin >> qi >> qx >> qy;
            --qi;
            x[qi] = qx, y[qi] = qy;
            for (int i = -1; i <= 1; ++i) {
                int ni = qi + i;
                if (ni <= 0 || ni >= n - 1) continue;

                int distSaved = dist(ni + 1, ni) + dist(ni, ni - 1) - dist(ni + 1, ni - 1);
                mst.set(ni, distSaved);
            }

            for (int i = -1; i <= 0; ++i) {
                int ni = qi + i;
                if (ni >= n - 1) continue;

                int distToRight = dist(ni, ni + 1);
                sst.set(ni, distToRight);
            }
        } else {
            int qi, qj;
            cin >> qi >> qj;
            --qi, --qj;
            if (qj - qi >= 2) cout << sst.sum(qi, qj) - mst.query(qi + 1, qj) << '\n';
            else cout << sst.sum(qi, qj) << '\n';
        }
    }
}
