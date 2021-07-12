#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 55;

bool cycleFound;
int vis[MX];
vector<int> conn[MX];
set<int> heads;

void dfs(int v) {
    vis[v] = 1;
    for (auto u : conn[v]) {
        if (vis[u] == 1) {
            cycleFound = true;
            heads.insert(u);
        } else if (vis[u] == 0) dfs(u);
    }
    vis[v] = 2;
}

void trav(int v) {
    vis[v] = 3;
    for (auto u : conn[v]) {
        if (vis[u] != 3) {
            trav(u);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int cnt = 1; cnt <= t; ++cnt) {
        int n, p; cin >> n >> p;
        vector<string> names(n);
        for (auto& i : names) cin >> i;
        for (int i = 0; i < n; ++i) {
            cycleFound = false;
            vis[i] = 0;
            conn[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            for (int j = 0; j < num; ++j) {
                int contact; cin >> contact;
                --contact;
                conn[i].push_back(contact);
            }
        }

        heads.clear();
        dfs(p - 1);
        for (auto head : heads) {
            trav(head);
        }
        cout << "Chain Email #" << cnt << ":\n";
        if (!cycleFound) cout << "Safe chain email!\n\n";
        else {
            for (int i = 0; i < n; ++i) {
                if (vis[i] == 3) cout << names[i] << ' ';
            }
            cout << "\n\n";
        }
    }
}
