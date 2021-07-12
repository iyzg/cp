#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
pair<ll, ll> fact[2505];

int a, b, c;
int tc = 1;

void solve() {
    cin >> a >> b >> c;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = fact[1] = {0, 1};
    for (ll i = 2; i < 2505; ++i) {
        fact[i].first = i * fact[i - 1].first;
        fact[i].second = i * fact[i - 1].second;
        fact[i].first += fact[i].second / MOD;
        fact[i].second %= MOD;
    }

    for (int i = 0; i < 2505; ++i) {
        cout << i << ": " << fact[i].first << ' ' << fact[i].second << '\n';
    }

    int t; cin >> t;
    for (; tc <= t; ++tc) {
        solve();
    }
}
