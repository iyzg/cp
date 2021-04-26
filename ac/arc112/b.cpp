#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll B, C;
ll ans = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> B >> C;
    if (B == 0) {
        ans = 1;
        if (C <= 1) {
            C = -1;
        } else {
            C -= 2;
            B = -1;
        }
    } else if (B > 0) {
        ans = min(2 * B + 1, C + 1);
        B = -(B + 1);
        C -= 3;
    } else {
        if (C < 2) ans = C + 1;
        else ans = min(abs(2 * B) + 1, C);
        --B;
        C -= 2;
    }

    if (C <= 0) {
        if (C == 0) ++ans;
        cout << ans;
        return 0;
    }

    // Updated cost @ -(B + 1)
    // cout << ans << endl;
    ll lb = B - ((C - 1) / 2);
    // cout << B << ' ' << lb << ' ' << C << endl;
    ans += (B - lb + 1) * 2;
    if (C % 2 == 0) ++ans;
    
    cout << ans;
}
