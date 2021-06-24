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

bool cont = true;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (!n && !m && !k) {
        cont = false;
        return;
    }

    vector<int> a(k), pre(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];

        pre[i] = a[i];
        if (i) pre[i] += pre[i - 1];
    }

    ll cur = n, ans = n, rep = m - 1;
    while (rep) {
        int toUse = min(rep, k);

        ans += (cur * toUse) + pre[toUse - 1];
        cur += a[toUse - 1];
        rep -= toUse;
    }
    
    cout << ans << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cont) 
        solve();
}
