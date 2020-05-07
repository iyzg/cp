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
const ll MOD = 998244353;
const ll MX = 1005;

int N;
vector<ll> a;
ll dp[MX][MX][2];

void memo(int l, int r, int side) {
    cout << l << " " << r << "\n";

    if (l > 0) {
        chmin(dp[l - 1][r][0], dp[l][r][0] + (a[l] - a[l - 1]));
        chmin(dp[l - 1][r][0], dp[l][r][1] + (a[r] - a[l - 1]));
        cout << dp[l - 1][r][0] << "\n";
    }
    if (r < N) {
        chmin(dp[l][r + 1][1], dp[l][r][0] + (a[r + 1] - a[l]));
        chmin(dp[l][r + 1][1], dp[l][r][1] + (a[r + 1] - a[r]));
        cout << dp[l][r + 1][1] << "\n";
    }
    
    // chmin(dp[l][r][0], dp[l][r][1]);
    // chmin(dp[l][r][1], dp[l][r][0]);
    if (l > 0) memo(l - 1, r, 0);
    if (r < N - 1) memo(l, r + 1 , 1);

}

void solve() {
    setIO("cowrun");
    cin >> N;
    a.resize(N + 1); a[0] = 0;
    for (int i = 0; i < N; i++) cin >> a[i + 1];
    sort(a.begin(), a.end());
    
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    
    for (int i = 0; i < N + 1; i++) {
        if (a[i] == 0) {
            dp[i][i][0] = 0;
            dp[i][i][1] = 0;
        }
    }
    
    for (int length = 1; length <= N; length++) {
        for (int i = 0; i <= N; i++) {
            // cout << i << " " << length << ": ";
            int outsidecows = N - (length - 1);
            if (i - length >= 0) {
                // cout << i - length << " " << i;
                chmin(dp[i - length][i][0], dp[i - length + 1][i][0] + outsidecows * (a[i - length + 1] - a[i - length]));
                chmin(dp[i - length][i][0], dp[i - length + 1][i][1] + outsidecows * (a[i] - a[i - length]));
                // cout << "- " << dp[i - length][i][0] << " / ";
            }
            
            if (i + length <= N) {
                // cout << i << " " << i + length;
                chmin(dp[i][i + length][1], dp[i][i + length - 1][0] + outsidecows * (a[i + length] - a[i]));
                chmin(dp[i][i + length][1], dp[i][i + length - 1][1] + outsidecows * (a[i + length] - a[i + length - 1]));
                // cout << "- " << dp[i][i + length][1];
            }
            // cout << "\n";
        }
    }
    

    
    cout << min(dp[0][N][0], dp[0][N][1]) << "\n";
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
