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
const ll MX = 1000001;

ll N;

void solve() {
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    if (N % 2 == 0) {
        ll dp[N][2];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = -INF;
            }
        }
        
        for (int i = 0; i < 2; i++) dp[i][1 - i] = a[i];
        
        for (int i = 0; i < N - 2; i++) {
            for (int extras = 0; extras < 2; extras++) {
                if (extras == 0) {
                    chmax(dp[i + 2][0], dp[i][0] + a[i + 2]);
                } else {
                    chmax(dp[i + 2][1], dp[i][1] + a[i + 2]);
                    if (i < N - 3) chmax(dp[i + 3][0], dp[i][1] + a[i + 3]);
                }
            }
        }
        
        cout << max(dp[N - 2][1], dp[N - 1][0]);
    } else {
        if (N == 3) {
            cout << max(max(a[0], a[1]), a[2]);
            return;
        }
        
        // ll ans = -INF;
        ll dp[N][3];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -INF;
            }
        }
        
        for (int i = 0; i < 3; i++) dp[i][2 - i] = a[i];
        
        for (int i = 0; i < N - 2; i++) {
            for (int extras = 0; extras < 3; extras++) {
                if (extras == 0) { 
                    chmax(dp[i + 2][0], dp[i][0] + a[i + 2]);
                } else if (extras == 1) {
                    chmax(dp[i + 2][1], dp[i][1] + a[i + 2]);
                    if (i < N - 3) chmax(dp[i + 3][0], dp[i][1] + a[i + 3]);
                } else {
                    chmax(dp[i + 2][2], dp[i][2] + a[i + 2]);
                    if (i < N - 3) chmax(dp[i + 3][1], dp[i][2] + a[i + 3]);
                    if (i < N - 4) chmax(dp[i + 4][0], dp[i][2] + a[i + 4]);
                }
            }
        }
        
        cout << max(max(dp[N - 3][2], dp[N - 2][1]), dp[N - 1][0]);
        
    }
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
