#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int a[20];

ll ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        ans |= a[i];
    }

    rep(i, 1, (1 << (n - 1))) {
        ll tmp = 0, cur = a[0];
        // cout << "i: " << i << '\n';
        for (int j = 1; j < n; ++j) {
            if ((bool)(i & (1 << j)) == (bool)(i & (1 << (j - 1)))) {
                cur |= a[j];
            } else {
                // cout << "has cur: " << cur << '\n';
                tmp ^= cur;
                cur = a[j];
            }

            if (j == n - 1) {
                // cout << "has cur: " << cur << '\n';
                tmp ^= cur;
            }
        }

        // cout << "has tmp: " << tmp << '\n';
        // cout << endl;
        ans = min(ans, tmp);
    }

    cout << ans;
}
