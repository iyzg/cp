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
const ll MX = 505;

ll dp[MX][MX], dist[MX][MX];
ll x[MX], y[MX];
int n, k;

int main() {
    setIO("marathon");
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int sk = 0; sk <= min(k, i - 1); ++sk) {
            for (int j = sk; j <= k; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - sk - 1][j - sk] + dist[i][i - sk - 1]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;
}
