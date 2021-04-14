#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long double PI = atan(1)*4;

int n;
int points[2][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, 2)
        rep(j, 0, 2)
            cin >> points[i][j];

    long double c = (long double)180 - (180 * (n - 2) / (long double)n);
    int dx = points[0][0] - points[1][0];
    int dy = points[0][1] - points[1][1];
    long double side = sqrt((long double)(dx * dx + dy * dy)) / 2;
    long double clen = 2 * side * side - 2 * side * side * cos(c * 180 / PI);
    cout << c << ' ' << side << clen;
}
