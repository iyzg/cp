#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
int percent;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int cnt = 1; cnt <= t; ++cnt) {
        cin >> s >> percent;
        int mins = 10 * (s[0] - '0') + (s[1] - '0'), secs = 10 * (s[3] - '0') + (s[4] - '0');
        int tot = 60 * mins + secs, range = tot * (long double)(percent / 100.0);

        int moves = 10000, adiff;
        string am, as;
        // cout << tot - range << ' ' << tot + range << '\n';
        for (int time = tot - range; time <= tot + range; ++time) {
            int nmin = time / 60, nsec = time % 60;
            string tmin = to_string(nmin), tsec = to_string(nsec);
            if (sz(tsec) == 1) tsec = '0' + tsec;
            if (!nmin) tmin = "";
            string comb = tmin + tsec;

            int tmoves = 0;
            for (int i = 1; i < sz(comb); ++i) {
                if (comb[i] == comb[i - 1]) ++tmoves;
                else tmoves += 2;
            }

            // cout << comb << " -> " << tmoves << '\n';
            if (tmoves < moves || (tmoves == moves && abs(tot - time) < adiff)) {
                moves = tmoves;
                am = tmin;
                as = tsec;
                adiff = abs(tot - time);
            }

            if (nmin >= 1 && nsec <= 39) {
                --nmin, nsec += 60;
            } else continue;

            tmin = to_string(nmin), tsec = to_string(nsec);
            if (sz(tsec) == 1) tsec = '0' + tsec;
            if (!nmin) tmin = "";
            comb = tmin + tsec;

            tmoves = 0;
            for (int i = 1; i < sz(comb); ++i) {
                if (comb[i] == comb[i - 1]) ++tmoves;
                else tmoves += 2;
            }
            // cout << comb << " -> " << tmoves << '\n';

            if (tmoves < moves || (tmoves == moves && abs(tot - time) < adiff)) {
                moves = tmoves;
                am = tmin;
                as = tsec;
                adiff = abs(tot - time);
            }
        }
        cout << "Case #" << cnt << ": " << am << as << '\n';
    }
}
