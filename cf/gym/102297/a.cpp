#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    vector<int> a(10);
    bool mack = false, zack = false;
    for (auto& i : a) {
        cin >> i;
        mack = mack | (i == 18);
        zack = zack | (i == 17);
    }
    for (auto i : a) cout << i << ' ';
    cout << '\n';
    if (mack && zack) {
        cout << "both\n";
    } else if (mack) {
        cout << "mack\n";
    } else if (zack) {
        cout << "zack\n";
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
