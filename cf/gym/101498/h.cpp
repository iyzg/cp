#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, s;

void solve() {
    cin >> n >> s;

    vector<int> ans(n);
    for (int i = 0; i < ceil(n / 2.0); ++i) {
        int cnt;
        n % 2 && i == n / 2 ? cnt = 1 : cnt = 2;
        int digit = min(9ll, s / cnt);

        // cout << i << ' ' << cnt << ' ' << digit << '\n';
        if (digit < 0 || (!i && digit == 0)) {
            // cout << "BROKE ON " << i << "\n";
            cout << -1 << '\n';
            return;
        }

        s -= cnt * digit;
        ans[i] = ans[n - 1 - i] = digit;
    }

    if (s) {
        cout << -1 << '\n';
        return;
    }

    for (auto i : ans) cout << i;
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
