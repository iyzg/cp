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
    int days = floor(log2(N));
    cout << days << "\n";
    ll b_cnt = 1, b_tot = 1;
    for (int i = 0; i < days; i++) {
        ll pos = min((N - b_tot) / (days - i), 2 * b_cnt);
        cout << max(pos - b_cnt, 0ll) << " ";
        chmax(b_cnt, pos);
        b_tot += b_cnt;
    }
    cout << "\n";
     
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T; cin >> T;
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
