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

struct segtree {
    int size;

    vector<ll> sums, mins;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;

        sums.assign(2 * size, 0ll);
        mins.assign(2 * size, -INF);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            mins[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            sums[x] += v;
            return;
        }

        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }
}

int main() {
    // setIO("haybales");
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    segtree st;
    st.init(n);
    st.build(a);

    while (q--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {

        } else if (op == 'P') {

        } else if (op == 'S') {

        }
    }
}
