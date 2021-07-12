#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt = 1;
int c, s, d;

void solve() {
    cin >> c >> s >> d;
    int ans = 0;
    while (c + s > 0) {
        ++ans;
        int tc = c, ts = s, td = d;
        int exposed = 0;

        // Residual
        if (td && ts < 2) {
            exposed = 2 - ts;
        } else if (td && ts >= 2) {
            exposed = ts % 2;
        } else if (ts) {
            exposed = ts % 2;
        }

        // Eating 
        if (tc) {
            --tc, ++ts;
        } else {
            --ts, ++td;
        }

        for (int i = 0; i < exposed; ++i) {
            if (tc) {
                --tc, ++ts;
            } else if (ts) {
                --ts, ++td;
            }
        }

        c = tc, s = ts, d = td;
    }
    cout << "Scenario #" << cnt << ": " << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (; cnt <= t; ++cnt) {
        solve();
    }
}
