#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e7;
const long double EPS = 0.000001;

int n;
int sg[52][52];
bitset<52> seen;

int dfs(int v, int amount) {
    if (v == n + 1) return amount;

    seen[v] = 1;

    for (int u = 0; u < n + 2; ++u) {
        if (sg[v][u] && !seen[u]) {
            int sent = dfs(u, min(amount, sg[v][u]));

            if (sent > 0) {
                sg[v][u] -= sent;
                sg[u][v] += sent;
                return sent;
            }
        }
    }

    return 0;
}

int flow() {
    int total = 0, sent = -1;
    while (sent != 0) {
        seen.reset();
        sent = dfs(n, 200);
        total += sent;
    }

    return total;
}


void solve() {
    cin >> n;
    // Matt as sink (n) and Sean as sink (n + 1)
    for (int i = 0; i < 52; ++i) {
        for (int j = 0; j < 52; ++j) {
            sg[i][j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        double prob; cin >> prob;
        sg[n][i] = (prob + EPS) * 100;
        ans += sg[n][i];
    }

    for (int i = 0; i < n; ++i) {
        double prob; cin >> prob;
        sg[i][n + 1] = (prob + EPS) * 100;
        ans += sg[i][n + 1];
    }

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double prob; cin >> prob;
            a[i][j] = (prob + EPS) * 100;
            ans += a[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sg[i][j] = a[i][j] + a[j][i];
        }
    }

    int remove = flow();
    // cout << ans << ' ' << remove << '\n';
    cout << fixed << setprecision(2) << (ans - remove + EPS) / 100.0 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
