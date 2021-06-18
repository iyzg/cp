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

struct segtree {
    int size;

    vector<ll> operations;
    vector<ll> sums, mins;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;

        operations.assign(2 * size, 0ll);
        sums.assign(2 * size, 0ll);
        mins.assign(2 * size, LLONG_MAX);
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                sums[x] = a[lx];
                mins[x] = a[lx];
            }
            return;
        }

        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void build(vector<ll> &a) {
        build(a, 0, 0, size);
    }

    void modify(ll l, ll r, ll v, ll x, ll lx, ll rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            sums[x] += (rx - lx) * v;
            mins[x] += v;
            operations[x] += v;
            return;
        }

        ll m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2] + (rx - lx) * operations[x];
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + operations[x];
    }

    void modify(ll l, ll r, ll v) {
        modify(l, r, v, 0, 0, size);
    }
    

    ll squery(ll l, ll r, ll x, ll lx, ll rx) {
        ll nl = max(l, lx), nr = min(r, rx);
		if (lx >= r || rx <= l) return 0;
		if (l <= lx && rx <= r) return sums[x];

		ll m = (lx + rx) / 2;
		ll q1 = squery(l, r, 2 * x + 1, lx, m);
		ll q2 = squery(l, r, 2 * x + 2, m, rx);
		return q1 + q2 + (nr - nl) * operations[x];
    }

    ll squery(ll l, ll r) {
        return squery(l, r, 0, 0, size);
    }

    ll mquery(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || rx <= l) return LLONG_MAX;
        if (l <= lx && rx <= r) return mins[x];

        ll m = (lx + rx) / 2;
        ll q1 = mquery(l, r, 2 * x + 1, lx, m);
        ll q2 = mquery(l, r, 2 * x + 2, m, rx);
        return min(q1, q2) + operations[x];
    }

    ll mquery(ll l, ll r) {
        return mquery(l, r, 0, 0, size);
    }
};

int main() {
    setIO("haybales");
    int n, q;
    cin >> n >> q;
    vector<ll> a(n); for (auto& i : a) cin >> i;

    segtree st;
    st.init(n);
    st.build(a);

    while (q--) {
        char op;
        cin >> op;
        if (op == 'M') {
            int a, b;
            cin >> a >> b;
            --a;
            cout << st.mquery(a, b) << '\n';
        } else if (op == 'P') {
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            st.modify(a, b, c);
        } else if (op == 'S') {
            int a, b;
            cin >> a >> b;
            --a;
            cout << st.squery(a, b) << '\n';
        }
    }
}
