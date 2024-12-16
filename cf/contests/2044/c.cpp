#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t, m, a, b, c;
int ar, br;
int res;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> m >> a >> b >> c;
        ar = br = m;
        res = 0;
        res += min(m, a);
        res += min(m, b);
        ar = m - min(m, a);
        br = m - min(m, b);
        res += min(ar + br, c);

        cout << res << '\n';
    }
}
