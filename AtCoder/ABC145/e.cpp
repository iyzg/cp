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
const ll MX = 3001;
 
int N, T;
ll ans = 0;
 
// # of dishes, time it takes to eat 
ll dp[MX][MX];
 
void solve() {
    cin >> N >> T;
    vector<l_l> dishes(N);
    for (int i = 0; i < N; i++) {
        cin >> dishes[i].first >> dishes[i].second;
    }
    sort(dishes.begin(), dishes.end());
    
    for (int dish = 1; dish <= N; dish++) {
        for (int time = 1; time <= T; time++) {
            dp[dish][time] = dp[dish - 1][time];
            chmax(ans, dp[dish - 1][time - 1] + dishes[dish - 1].second);
            
            ll maxWithDish = 0;
            
            if (time >= dishes[dish - 1].first) {
                maxWithDish = dishes[dish - 1].second;
                maxWithDish += dp[dish - 1][time - dishes[dish - 1].first];
            }
            
            
            chmax(dp[dish][time], maxWithDish);
        }
    }
    
    cout << ans;
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll Q = 1; // cin >> T;
    while (Q--) solve();
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
