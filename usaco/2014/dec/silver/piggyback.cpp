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

const int MX = 4 * 1e4 + 5;

int b, e, p, n, m;
vector<int> be(MX, -1), ee(MX, -1), pe(MX, -1);
vector<int> g[MX];

int main() {
    setIO("piggyback");

    cin >> b >> e >> p >> n >> m;
    vector<pii> pairs;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    be[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();


        for (auto conn : g[v]) {
            if (be[conn] == -1) {
                q.push(conn);
                be[conn] = be[v] + 1;
            }
        }
    }


    ee[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();


        for (auto conn : g[v]) {
            if (ee[conn] == -1) {
                q.push(conn);
                ee[conn] = ee[v] + 1;
            }
        }
    }

    pe[n - 1] = 0;
    q.push(n - 1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto conn : g[v]) {
            if (pe[conn] == -1) {
                q.push(conn);
                pe[conn] = pe[v] + 1;
            }
        }
    }

    int ans = 1e8;
    for (int i = 0; i < n; ++i) {
        if (be[i] == -1 || ee[i] == -1 || pe[i] == -1) continue;
        ans = min(ans, be[i] * b + ee[i] * e + pe[i] * p);
    }

    cout << ans;
}
