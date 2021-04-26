#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 998244353;
const ll MX = 2 * 1e5 + 5;

ll n, f[MX];
bool checked[MX];
ll groups = 0;

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) 
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
    }
    for (int i = 0; i < n; ++i) {
        if (checked[i]) continue;
        set<int> found;
        found.insert(i);
        int nxt = f[i];

        while (found.find(nxt) == found.end()) {
            if (checked[nxt]) {
                break;
            }
            found.insert(nxt);
            nxt = f[nxt];
        }

        if (found.find(nxt) != found.end()) ++groups;
        for (int i : found) checked[i] = true;
    }

    // cout << groups << '\n';
    cout << binpow(2, groups) - 1;
}
