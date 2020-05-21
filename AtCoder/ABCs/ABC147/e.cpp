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
const ll MX = 80;

int H, W;
ll a[MX][MX], b[MX][MX], c[MX][MX];
bool dp[MX][MX][30000];

// Directions
int dy[2] = {0, 1}, dx[2] = {1, 0};

void solve() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}
	
    for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 30000; k++) {
				dp[i][j][k] = false;
			}
		}
	}
	
	dp[0][0][15000 + a[0][0] - b[0][0]] = true;
	dp[0][0][15000 + b[0][0] - a[0][0]] = true;
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 30000; k++) {
				if (!dp[i][j][k]) continue;
				if (i < H - 1) {
					dp[i + 1][j][k + a[i + 1][j] - b[i + 1][j]] = true;
					dp[i + 1][j][k + b[i + 1][j] - a[i + 1][j]] = true;
				}
				if (j < W - 1) {
					dp[i][j + 1][k + a[i][j + 1] - b[i][j + 1]] = true;
					dp[i][j + 1][k + b[i][j + 1] - a[i][j + 1]] = true;
				}
			}
		}
	}
	
	int ans = 100000;
	for (int i = 0; i < 30000; i++) {
		if (dp[H - 1][W - 1][i]) {
			// cout << abs(15000 - i) << "\n";
			chmin(ans, abs(15000 - i));
		}
	}
	cout << ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll testCases = 1; // cin >> testCases;
    while (testCases--) solve();
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
