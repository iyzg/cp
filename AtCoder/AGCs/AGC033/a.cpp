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
const ll MX = 1005;

int H, W;
char c;
int grid[MX][MX];
bool used[MX][MX];

int ans = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void solve() {
    cin >> H >> W;
    
    queue<i_i> q;
    
    for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c;
			if (c == '#') {
				q.push({i, j});
				used[i][j] = true;
				grid[i][j] = 0;
			}
		}
	}
	
	while (!q.empty()) {
		i_i v = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = v.first + dy[i], b = v.second + dx[i];
			if (a < 0 || a >= H || b < 0 || b >= W) continue;
			if (used[a][b]) continue;
			q.push({a, b});
			used[a][b] = true;
			grid[a][b] = grid[v.first][v.second] + 1;
			chmax(ans, grid[a][b]);
		}
	}
	cout << ans;
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
