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
long double ax, ay, bx, by;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> ax >> ay >> bx >> by;
    long double mx = (ax + bx) / 2.0;
    long double my = (ay + by) / 2.0;
    long double dist = sqrt(pow(ax - mx, 2) + pow(ay - my, 2)); 
    // cout << mx << ' ' << my << ' ' << dist << endl;
    long double azimuth = atan2(ay - my, ax - mx);
    azimuth += (2.0 * PI) / n;
    // cout << azimuth * 180 / PI;
    cout << fixed << setprecision(5) << mx + dist * cos(azimuth) << ' ' << my + dist * sin(azimuth);
}
