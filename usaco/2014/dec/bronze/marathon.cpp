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

int n;
ll tot, m;

int main() {
    setIO("marathon");
    cin >> n; 
    vector<pii> ps(n);
    for (auto& p : ps) {
        cin >> p.first >> p.second;
    }

    for (int i = 1; i < n - 1; ++i) {
        ll dist = abs(ps[i].first - ps[i - 1].first) + abs(ps[i].second - ps[i - 1].second);
        ll nxt = abs(ps[i].first - ps[i + 1].first) + abs(ps[i].second - ps[i + 1].second);
        ll skipDist = abs(ps[i + 1].first - ps[i - 1].first) + abs(ps[i + 1].second - ps[i - 1].second);
        skipDist = dist + nxt - skipDist;

        tot += dist;
        m = max(m, skipDist);
    }

    tot += abs(ps[n - 1].first - ps[n - 2].first) + abs(ps[n - 1].second - ps[n - 2].second);

    // cout << tot << '\n';
    cout << tot - m;
}
