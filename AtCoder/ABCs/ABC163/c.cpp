#include <bits/stdc++.h>
using namespace std;

/* Typedefs */

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

/* Consts */

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;

int N;

void solve() {
    cin >> N;
    vector<int> a(N - 1), ans(N);
    for(int i = 0; i < N - 1; i++) {
        cin >> a[i];
        ans[i] = 0;
    }
    for(int i = 0; i < N - 1; i++) ans[a[i] - 1]++;
    for(int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    // ll T; cin >> T;
    // while (T--) solve();
    solve();
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
