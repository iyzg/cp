#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, m;
void solve() {
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (!((n + m) % 2) && !(n % 2)) cout << "abdullah\n";
    else cout << "hasan\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
