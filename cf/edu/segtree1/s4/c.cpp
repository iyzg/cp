#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct sumst {
    int size;
    vector<int> sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0);
    }

    void reset(int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = 0;
            return;
        }

        int m = (lx + rx) / 2;
        reset(2 * x + 1, lx, m);
        reset(2 * x + 2, m, rx);

        sums[x] = 0;
    }

    void reset() {
        reset(0, 0, size);
    }

    void inc(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            ++sums[x];
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            inc(i, 2 * x + 1, lx, m);
        } else {
            inc(i, 2 * x + 2, m, rx);
        }

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void inc(int i) {
        inc(i, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) { 
        if (l >= rx || r <= lx) return 0;
        if (lx >= l && rx <= r) return sums[x];

        int m = (lx + rx) / 2;
        int q1 = query(l, r, 2 * x + 1, lx, m);
        int q2 = query(l, r, 2 * x + 2, m, rx);
        return q1 + q2;
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

struct segtree {
    int size;
    vector<sumst> nums;
    vector<ll> invs;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        nums.assign(2 * size, sumst());
        invs.assign(2 * size, 0ll);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                nums[x].reset();
                nums[x].inc(a[lx]);
                invs[x] = 0;
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        invs[x] = invs[2 * x + 1] + invs[2 * x + 2];
        for (auto n : nums[2 * x + 2]) {
            invs[x] += nums[2 * x + 1].query(n + 1, 41);
        }
        nums[x].insert(all(nums[2 * x + 1]));
        nums[x].insert(all(nums[2 * x + 2]));
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void modify(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx == i) {
                nums[x].clear();
                nums[x].insert(v);
                invs[x] = 0;
            }
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            modify(i, v, 2 * x + 1, lx, m);
        } else {
            modify(i, v, 2 * x + 2, m, rx);
        }

        invs[x] = invs[2 * x + 1] + invs[2 * x + 2];
        for (auto n : nums[2 * x + 2]) {
            auto it = nums[2 * x + 1].upper_bound(n);
            invs[x] += distance(it, nums[2 * x + 1].end());
        }

        nums[x].clear();
        nums[x].insert(all(nums[2 * x + 1]));
        nums[x].insert(all(nums[2 * x + 2]));
    }

    void modify(int i, int v) {
        modify(i, v, 0, 0, size);
    }

    pair<multiset<int>, int> query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {multiset<int>(), 0};
        if (lx >= l && rx <= r) return {nums[x], invs[x]};

        int m = (lx + rx) / 2;
        pair<multiset<int>, int> q1 = query(l, r, 2 * x + 1, lx, m);
        pair<multiset<int>, int> q2 = query(l, r, 2 * x + 2, m, rx);

        pair<multiset<int>, int> res = {multiset<int>(), q1.second + q2.second};
        for (auto n : q2.first) {
            auto it = q1.first.upper_bound(n);
            res.second += distance(it, q1.first.end());
        }

        res.first.insert(all(q1.first));
        res.first.insert(all(q2.first));
        return res;
    }

    pair<multiset<int>, int> query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n); for (auto &i : a) cin >> i;

    segtree st;
    st.init(n);
    st.build(a);

    // cout << st.size << endl;
    // for (int i = 0; i < 2 * st.size; ++i) {
        // cout << st.invs[i] << ' ';
    // }
    // cout << endl;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        --x;
        if (op == 1) {
            cout << st.query(x, y).second << '\n';
        } else {
            st.modify(x, y);
        }
    }
}
