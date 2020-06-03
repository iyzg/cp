#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 300;

int h, w, k;

int grid[MX][MX], ans[MX][MX];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w >> k;
    vector<pair<int, int>> a;
    
    for (int i = 0; i < h; i++) {
		string s; cin >> s;
		for (int j = 0; j < w; j++) {
			grid[i][j] = (s[j] == '#');
			if (s[j] == '#') {
				a.push_back({i, j});
			}
		}
	}
	
	int group = 0;
	for (auto& i : a) {
		group++;
		ans[i.first][i.second] = group;
		for (int j = i.second - 1; j >= 0; --j) {
			if (!ans[i.first][j] && !grid[i.first][j]) ans[i.first][j] = group;
			else break;
		}
		for (int j = i.second + 1; j < w; j++) {
			if (!ans[i.first][j] && !grid[i.first][j]) ans[i.first][j] = group;
			else break;			
		}
	}
	
	for (int i = 1; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!ans[i][j]) ans[i][j] = ans[i - 1][j];
		}
	} 
	
	for (int i = h - 2; i >= 0; --i) {
		for (int j = 0; j < w; j++) {
			if (!ans[i][j]) ans[i][j] = ans[i + 1][j];
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}
