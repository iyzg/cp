#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 2005;

int N;
ll dp[MX][MX];
vector<l_l> a;
ll ans = 0;

void solve() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    for (int l = 0; l <= N; l++) {
        for (int r = N; r >= l; r--) {
            int ch = r - l;
            
            if (l > 0) {
                ll tmp = dp[l - 1][r];
                tmp += a[ch].first * abs(a[ch].second - (l - 1));
                chmax(dp[l][r], tmp);
            }
            
            if (r < N) {
                ll tmp = dp[l][r + 1];
                tmp += a[ch].first * abs(r - a[ch].second);
                chmax(dp[l][r], tmp);
            }
            // cout << l << " " << r << ": " << dp[l][r] << "\n";
        }
    }
    
    for (int i = 0; i <= N; i++) {
        chmax(ans, dp[i][i]);
    }
    cout << ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
