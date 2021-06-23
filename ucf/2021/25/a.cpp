#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

ll n, tmp, cnt, lb, ub; 

void solve() {
    cin >> n; tmp = n, cnt = 0;
    while (tmp != 0) {
        ll lastDigit = tmp % 10;
        ++cnt;

        if (!lastDigit) {
            tmp /= 10;
            continue;
        }

        if (tmp < 10) {
            cout << "not absurd\n";
            return;
        }

        tmp /= 10;

        if (lastDigit == 5) {
            lb = n - 5 * powl(10, cnt - 1);
            ub = n + 5 * powl(10, cnt - 1);
        } else if (lastDigit < 5) {
            lb = n - lastDigit * powl(10, cnt - 1);
            ub = n + (5 - lastDigit) * powl(10, cnt - 1);
        } else {
            lb = n - (lastDigit - 5) * powl(10, cnt - 1);
            ub = n + (10 - lastDigit) * powl(10, cnt - 1);
        }
        break;
    }

    // cout << lb << ' ' << ub << '\n';
    long double lr = 0.95 * n, ur = 1.05 * n;
    if (lr <= lb || ub <= ur) cout << "absurd\n";
    else cout << "not absurd\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c; cin >> c;
    while (c--)
        solve();
}
