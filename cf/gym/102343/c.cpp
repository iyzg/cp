#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long double EPS = 0.01;

long double PI = acosl(-1);

long double l, w, h, x, y, a;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> w >> h >> x >> y >> a;
    long double endx = cosl(a * PI / (long double)180.0) * h, endy = sinl(a * PI / (long double)180.0) * h;
    if (endx + x - EPS > w || endx + x + EPS < 0 || endy + y - EPS > l || endy + y + EPS < 0) cout << "NO";
    else cout << "YES";

}
