#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t;
ll k, l1, l2, r1, r2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    double eps = 1e-10;
    rep(i, 0, t) {
        ll ans = 0;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll kp = 1;
        for (int p = 0; p < 32; ++p) {
            ll rl = (l2 + kp - 1) / kp;  // Ceiling division
            ll rr = r2 / kp;             // Floor division
            
            rl = max(rl, l1);
            rr = min(rr, r1);
            if (rr >= rl) ans += rr - rl + 1;
            if (k > (1LL<<60)/kp) break; // Prevent overflow
            kp *= k;
        }

        cout << ans << '\n';
    }
}
