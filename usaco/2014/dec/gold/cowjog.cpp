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

ll n, t;

int main() {
    setIO("cowjog");
    
    cin >> n >> t;
    multiset<ll> ends;
    for (int i = 0; i < n; ++i) {
        ll p, s, end;
        cin >> p >> s;
        end = p + (s * t);
        auto it = ends.lower_bound(end);

        if (it == ends.begin()) {
            ends.insert(end);
        } else {
            it = prev(it);
            ends.erase(it);
            ends.insert(end);
        }
    }

    cout << sz(ends);
}
