#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); } void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

const ll INF = 1e18 + 5;

ll N, H;

ll ans = -1;
ll dp[1ll << 20], weight[1ll << 20], height[1ll << 20];

int main() {
    setIO("guard");
    cin >> N >> H;
    vector<pair<ll, pair<ll, ll>>> cows(N);
    for (auto& cow : cows) {
        cin >> cow.first >> cow.second.first >> cow.second.second;
    }

    dp[0] = INF;
    weight[0] = 0;
    height[0] = 0;

    for (ll i = 1; i < (1ll << N); ++i) {
        for (ll j = 0; j < N; ++j) {
            if (i & (1ll << j)) {
                weight[i] += cows[j].second.first;
                height[i] += cows[j].first;
            }
        }
    }

    for (ll i = 1; i < (1ll << N); ++i) {
        dp[i] = -INF;
        for (ll j = 0; j < N; ++j) {
            if (i & (1ll << j)) {
                ll wout = i ^ (1ll << j);
                dp[i] = max(dp[i], min(dp[wout], cows[j].second.second - weight[wout]));
            }
        }

        if (height[i] >= H) ans = max(ans, dp[i]);
    }

    ans == -1 ? cout << "Mark is too tall" : cout << ans;
}
