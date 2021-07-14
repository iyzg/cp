#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long double PI = 3.14159265358979;

long double s, r;

void solve() {
    cin >> s >> r;
    if (s / 2 >= r) {
        cout << fixed << setprecision(2) << PI * r * r << '\n';
    } else if (r >= sqrt(2 * (s / 2 * s / 2))) {
        cout << fixed << setprecision(2) << s * s << '\n';
    } else {
        long double angle = acos((s / 2) / r);
        long double triangle = (1.0 / 2) * (s / 2) * sin(angle) * r;
        long double circle = (PI / 4 - angle) / 2 * r * r;
        cout << fixed << setprecision(2) << 8 * (triangle + circle) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
