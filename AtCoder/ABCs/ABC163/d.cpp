#include <bits/stdc++.h>
using namespace std;

/* Typedefs */

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

/* Consts */

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll MX = 1000001;

int N, K;
ll ans = 0;

void solve() {
    cin >> N >> K;
    ll lb = 0, rb = 0, lcurr = K, rcurr = N - K;
    for (int i = 0; i < K; i++) {
        lb += i;
        rb += N - i;
    }
    while (lcurr <= N + 1) {
        // cout << lb << " " << rb << "\n";
        ans += (rb - lb + 1) % MOD;
        lb += lcurr++;
        rb += rcurr--;
    }
    cout << ans % MOD;
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
