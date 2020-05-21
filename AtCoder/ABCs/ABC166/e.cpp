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
const ll MX = 200005;

ll N, A, ans = 0;
vector<int> a;
int add[MX];

void solve() {
    cin >> N; a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (i - (a[i] - 1) >= 0) add[i - (a[i] - 1)]++;
    }
    
    for (int i = 0; i < N; i++) {
        if (i + a[i] + 1 < N) ans += add[i + a[i] + 1];
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
