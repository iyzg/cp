#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 100;

int H, W, N;
int a[MX*MX];
int grid[MX][MX];
int color = 1;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> H >> W >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	
	for (int i = 0; i < H; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < W; j++) {
				if (a[color - 1] > 0) {
					grid[i][j] = color;
					a[color - 1]--;
				} else {
					color++;
					grid[i][j] = color;
					a[color - 1]--;
				}
				// cout << i << " " << j << " " << color << "\n";
			}
		} else {
			for (int j = W - 1; j >= 0; --j) {
				if (a[color - 1] > 0) {
					grid[i][j] = color;
					a[color - 1]--;
				} else {
					color++;
					grid[i][j] = color;
					a[color - 1]--;
				}					
			}
		}
	}
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}
