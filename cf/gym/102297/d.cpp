#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll d, l, s;

void solve() {
    cin >> d >> l >> s;
    ll tot = 0;

    ll lm = 10000, sm = 10000;
    ll lcur = 0, scur = 0;
    for (int i = 0; i < d; ++i) {
        ll cups, lcost, scost;
        cin >> cups >> lcost >> scost;
        lm = min(lm, lcost), sm = min(sm, scost);

        ll ln = cups * l - lcur;
        tot += ln * lm;
        lcur += ln;
        lcur -= cups * l;

        ll sugarBagsNeeded = ceil((cups * s - scur) / 80.0);
        tot += sugarBagsNeeded * sm;
        scur += sugarBagsNeeded * 80;
        scur -= cups * s;
    }
    cout << tot << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
