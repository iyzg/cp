#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int tc = 1;

int d, n;
void solve() {
    cin >> d >> n;

    cout << "Grid #" << tc << ": ";
    int needed = 2 * (n - 1) - 1;
    if (needed + d >= n * n) cout << "impossible\n";
    else cout << d * 2 * (n - 1) << "\n";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; tc <= t; ++tc) {
        solve();
    }
}
