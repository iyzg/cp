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

const int MX = 1e5 + 5;

ll dp[2][MX], passPen[2][MX], dribPen[2][MX];

void solve() {
    int n, l1, l2, s1, s2;
    cin >> n >> l1 >> l2 >> s1 >> s2;

    rep(i, 0, n - 1)
        cin >> passPen[0][i];
    rep(i, 0, n - 1)
        cin >> dribPen[0][i];
    rep(i, 0, n - 1)
        cin >> passPen[1][i];
    rep(i, 0, n - 1)
        cin >> dribPen[1][i];

    dp[0][0] = l1, dp[1][0] = l2;

    for (int i = 1; i < n; ++i) {
        dp[0][i] = min(dp[0][i - 1] + dribPen[0][i - 1], dp[1][i - 1] + passPen[1][i - 1]);
        dp[1][i] = min(dp[1][i - 1] + dribPen[1][i - 1], dp[0][i - 1] + passPen[0][i - 1]);
    }
    
    cout << min(dp[0][n - 1] + s1, dp[1][n - 1] + s2) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
