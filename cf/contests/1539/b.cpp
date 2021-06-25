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

ll n, q;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    cin >> s;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = s[i - 1] - 'a' + 1;
        if (i > 1) pre[i] += pre[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        cout << pre[r] - pre[l] << '\n';
    }
}
