#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll x, n;

void solve() {
    cin >> x >> n;
    if (n > x) {
        cout << "-1\n";
        return;
    }

    vector<int> a;
    while (n) {
        ll b = round((long double)x / n);
        a.push_back(b);
        x -= b;
        --n;
    }
    sort(all(a));
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
