#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e7;
int n;

void solve() {
    cin >> n;
    vector<int> a(n), low(1e6 + 5, INF);
    for (auto& i : a) cin >> i;
    sort(all(a));
    ll ans = 0;
    for (auto i : a) {
        if (low[i] <= i) ans += low[i];
        else {
            for (int j = i; j < 1e6 + 5; j += i) {
                low[j] = min(low[j], i);
            }
            ans += i;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
