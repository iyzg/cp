#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;

long double A, B, H, M;

void solve() {
    cin >> A >> B >> H >> M;
    
    double pi = acos(-1.0);
    double ax = A * cos(2 * pi * (H * 60 + M) / 720);
    double ay = A * sin(2 * pi * (H * 60 + M) / 720);
	double bx = B * cos(2 * pi * M / 60);
	double by = B * sin(2 * pi * M / 60);
    cout << fixed << setprecision(20) << hypot(ax - bx, ay - by);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
