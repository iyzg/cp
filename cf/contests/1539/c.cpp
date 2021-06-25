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

ll n, k, x;
ll groups = 1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));

    vector<ll> needed;

    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > x) {
            ++groups;
            needed.push_back((a[i] - a[i - 1] - 1) / x);
        }
    }

    sort(all(needed));
    for (auto i : needed) {
        if (k >= i) {
            k -= i;
            --groups;
        }
    }

    cout << groups;
}
