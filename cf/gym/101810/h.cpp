#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
void solve() {
    cin >> n;
    vector<int> a(2 * n);
    for (auto& i : a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i] + a[2 * n - i - 1]);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}
