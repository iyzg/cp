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
const ll MX = 500;

int N, M;
int a[MX][MX], b[MX][MX];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}
	if (a[0][0] != b[0][0] || a[N - 1][M - 1] != b[N - 1][M - 1]) {
		cout << "NO";
		return;
	}
	
	map<int, int> ad, bd;
	bool pos = true;
	for (int r = 1; r < N; r++) {
		if (!pos) break;
		int row = r, col = 0;
		while (row >= 0 && col < M) {
			ad[a[row][col]]++;
			bd[b[row][col]]++;
			row--; col++;
		}
		for (auto& i : ad) {
			if (bd.find(i.first) == bd.end() || bd[i.first] != i.second) {
				pos = false;
				break;
			}
		}
		ad.clear();
		bd.clear();
	}
	
	for (int c = 1; c < M - 1; c++) {
		if (!pos) break;
		int row = N - 1, col = c; 
		while (row >= 0 && col < M) {
			ad[a[row][col]]++;
			bd[b[row][col]]++;
			row--; col++;
		}
		for (auto& i : ad) {
			if (bd.find(i.first) == bd.end() || bd[i.first] != i.second) {
				pos = false;
				break;
			}
		}
		ad.clear();
		bd.clear();
	}
	
	if (pos) cout << "YES";
	else cout << "NO";
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
