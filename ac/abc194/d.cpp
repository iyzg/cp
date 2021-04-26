#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
long double ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        // cout << i << ' ' << n << '\n';
        ans += 1 / (long double)(i / (long double)n);
    }
    cout << setprecision(6) << fixed << ans;
}
