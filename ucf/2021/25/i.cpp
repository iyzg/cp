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

void solve() {
    map<string, int> teams;
    vector<int> losses(16, 0);
    int inc = 1;
    for (int i = 0; i < 16; ++i) {
        string t1, t2;
        int s1, s2;
        cin >> t1 >> t2 >> s1 >> s2;

        if (!teams.count(t1)) teams[t1] = inc++;
        if (!teams.count(t2)) teams[t2] = inc++;

        if (s1 > s2) ++losses[teams[t2]];
        else ++losses[teams[t1]];
    }

    for (int i = 0; i < 16; ++i) {
        if (!losses[i]) {
            for (auto team : teams) {
                if (team.second == i) {
                    cout << team.first << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
