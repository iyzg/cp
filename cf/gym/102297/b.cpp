#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    vector<int> a(6);
    for (auto& i : a) cin >> i;
    bool count = false, color = false;
    if (a[0] + a[1] + a[2] > a[3] + a[4] + a[5]) count = true;
    if (a[0] > a[3] || (a[0] == a[3] && a[1] > a[4]) || (a[0] == a[3] && a[1] == a[4] && a[2] > a[5])) {
        color = true;
    }

    for (auto i : a) cout << i << ' ';
    cout << '\n';
    if (count && color) {
        cout << "both\n";
    } else if (count) {
        cout << "count\n";
    } else if (color) {
        cout << "color\n";
    } else {
        cout << "none\n";
    }
    cout << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    rep(i, 0, n)
        solve();
}
