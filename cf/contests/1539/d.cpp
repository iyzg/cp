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
 
const int MX = 1e5 + 5;
const ll INF = 1e18;
 
ll bought = 0, total = 0;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> items(n);
    for (auto& i : items) {
        cin >> i.second >> i.first;
    }
    sort(all(items));
    
    int bt = n - 1;
    for (int i = 0; i < n; ++i) {
        ll needed = max(0ll, items[i].first - bought);
        for (; bt >= 0;) {
            if (!needed) break;

            ll buys = min(needed, items[bt].second);
            total += 2 * buys;
            bought += buys;
            items[bt].second -= buys;
            needed -= buys;
            if (!items[bt].second) --bt;
        }

        total += items[i].second;
        bought += items[i].second;
        items[i].second = 0;
    }
    cout << total;
}
