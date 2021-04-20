#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 1500;

int h, w, n, m;
set<pii> rows[MX], cols[MX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w >> n >> m;
    rep(i, 0, n) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        rows[r].insert({c, 1});
        cols[c].insert({r, 1});
    }

    rep(i, 0, m) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        rows[r].insert({c, 0});
        cols[c].insert({r, 0});
    }

    int ans = 0;
    rep(i, 0, h) {
        rep(j, 0, w) {
            bool lit = false;
            auto rit = rows[i].lower_bound({j, -1});
            auto cit = cols[j].lower_bound({i, -1});
            if (rit != rows[i].end() && rit->second == 1) lit = true;
            if (cit != cols[j].end() && cit->second == 1) lit = true;
            
            if (rit != rows[i].end() && rit->first == j && rit->second == 0) continue; 
            if (cit != cols[j].end() && cit->first == i && cit->second == 0) continue;

            if (rit != rows[i].begin()) --rit;
            if (cit != cols[j].begin()) --cit;
            
            if (rit != rows[i].end() && rit->second == 1) lit = true;
            if (cit != cols[j].end() && cit->second == 1) lit = true;

            // if (lit) cout << i << ' ' << j << ' ' << '\n';
            if (lit) ++ans;
        }
    }


    cout << ans;
}
