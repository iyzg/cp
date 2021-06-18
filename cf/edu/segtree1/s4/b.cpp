#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int MOD;

struct segtree {
    int size;
    vector<tuple<ll, ll, ll, ll>> matrices;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        matrices.assign(2 * size, make_tuple(0, 0, 0, 0));
    }

    void build(vector<tuple<ll, ll, ll, ll>> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                matrices[x] = a[lx];
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        tuple<ll, ll, ll, ll> m1 = matrices[2 * x + 1];
        tuple<ll, ll, ll, ll> m2 = matrices[2 * x + 2];
        get<0>(matrices[x]) = (get<0>(m1) * get<0>(m2) % MOD + get<1>(m1) * get<2>(m2) % MOD) % MOD;
        get<1>(matrices[x]) = (get<0>(m1) * get<1>(m2) % MOD + get<1>(m1) * get<3>(m2) % MOD) % MOD;
        get<2>(matrices[x]) = (get<2>(m1) * get<0>(m2) % MOD + get<3>(m1) * get<2>(m2) % MOD) % MOD;
        get<3>(matrices[x]) = (get<2>(m1) * get<1>(m2) % MOD + get<3>(m1) * get<3>(m2) % MOD) % MOD;
    }

    void build(vector<tuple<ll, ll, ll ,ll>> &a) {
        build(a, 0, 0, size);
    }

    tuple<ll, ll, ll, ll> query(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) return make_tuple(-1, -1, -1, -1);
        if (l <= lx && r >= rx) return matrices[x];

        int m = (lx + rx) / 2;
        tuple<ll, ll, ll, ll> q1 = query(l, r, 2 * x + 1, lx, m);
        tuple<ll, ll, ll, ll> q2 = query(l, r, 2 * x + 2, m, rx);
        if (get<0>(q1) == -1) return q2;
        if (get<0>(q2) == -1) return q1;

        tuple<ll, ll, ll, ll> res;
        get<0>(res) = (get<0>(q1) * get<0>(q2) % MOD + get<1>(q1) * get<2>(q2) % MOD) % MOD;
        get<1>(res) = (get<0>(q1) * get<1>(q2) % MOD + get<1>(q1) * get<3>(q2) % MOD) % MOD;
        get<2>(res) = (get<2>(q1) * get<0>(q2) % MOD + get<3>(q1) * get<2>(q2) % MOD) % MOD;
        get<3>(res) = (get<2>(q1) * get<1>(q2) % MOD + get<3>(q1) * get<3>(q2) % MOD) % MOD;

        return res;
    }

    tuple<ll, ll, ll, ll> query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> MOD >> n >> m;
    vector<tuple<ll, ll, ll, ll>> a(n);
    for (auto& [i, j, k, l] : a) {
        cin >> i >> j >> k >> l;
        i %= MOD, j %= MOD, k %= MOD, l %= MOD;
    }

    segtree st;
    st.init(n);
    st.build(a);

    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        tuple<ll, ll, ll, ll> res = st.query(l, r);
        cout << get<0>(res) << ' ' << get<1>(res) << '\n' << get<2>(res) << ' ' << get<3>(res) << "\n\n";
    }
}
