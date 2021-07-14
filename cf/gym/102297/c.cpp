#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int tc = 1;
int s, b, m;

void solve() {
    cin >> s >> b >> m;
    cout << "Practice #" << tc << ": " << s << ' ' << b << '\n';
    for (int i = 0; i < m; ++i) {
        int cnt; cin >> cnt;
        while (b <= cnt) b *= 2;
        b -= cnt;
        cout << cnt << ' ' << b << '\n';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; tc <= t; ++tc) {
        solve();
    }
}
