#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 505;
int te = 1;
ll dp[MX][MX];

int n;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            dp[i][j] = 0;
        }
    }

    ll ans = -1;

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i];
        ans = max(ans, dp[i][1]);
        for (int len = 2; len <= i / 2; ++len) {
            for (int j = 1; j < i; ++j) {
                dp[i][len] = max(dp[i][len], dp[j][len - 1] + a[i]);
            }
            ans = max(ans, dp[i][len]);
        }
    }


    cout << "Spree #" << te << ": " << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; te <= t; ++te) {
        solve();
    }
}
