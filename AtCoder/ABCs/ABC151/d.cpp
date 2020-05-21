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

int H, W;
char grid[20][20];
int group[20][20];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int ans = 0;

void solve() {
	cin >> H >> W;
	bool wrong = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {	
			cin >> grid[i][j];
			if (grid[i][j] == '#') wrong = true;
		}
	}
	
	if (!wrong) {
		cout << H + W - 2;
		return;
	}
	
	int curr = 0;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			curr++;
			if (grid[r][c] == '.') {
				queue<pair<l_l, int>> q;
				q.push({{r, c}, 0});
				while (!q.empty()) { 
					pair<l_l, int> v = q.front();
					group[v.first.first][v.first.second] = curr;
					q.pop();
					chmax(ans, v.second);
					for (int i = 0; i < 4; i++) {
						int a = v.first.first + dy[i], b = v.first.second + dx[i];
						if (a < 0 || a >= H || b < 0 || b >= W) continue;
						if (group[a][b] == curr) continue;
						if (grid[a][b] != '.') continue;
						q.push({{a, b}, v.second + 1});
					}
				}
			}
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
