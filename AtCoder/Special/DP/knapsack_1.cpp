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

ll N, W;

void solve() {
    cin >> N >> W;
    vector<l_l> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second;
    }
    
    ll dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }
    for (int item = 1; item <= N; item++) {
        for (int capacity = 1; capacity <= W; capacity++) {
            dp[item][capacity] = dp[item - 1][capacity];
            ll maxWithItem = 0;
            
            if (capacity >= items[item - 1].first) {
                maxWithItem = items[item - 1].second;
                maxWithItem += dp[item - 1][capacity - items[item - 1].first];
            }
            
            chmax(dp[item][capacity], maxWithItem);
        }
    }
    
    cout << dp[N][W];
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
