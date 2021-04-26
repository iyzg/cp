#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 15;

int ans;
int H, W;
bool grid[MX][MX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> H >> W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c; cin >> c;
            if (c == '#') grid[i][j] = true;
        }
    }

    // Check right if #o side
    for (int col = 1; col < W; ++col) {
        for (int row = 1; row < H; ++row) {
            if (grid[row][col] && !grid[row][col + 1]) {
                ++ans;
                while (grid[row][col] && !grid[row][col + 1]) ++row;
            }
        }
    }

    for (int col = 1; col < W; ++col) {
        for (int row = 1; row < H; ++row) {
            if (grid[row][col] && !grid[row][col - 1]) {
                ++ans;
                while (grid[row][col] && !grid[row][col - 1]) ++row;
            }
        }
    }

    for (int row = 1; row < H; ++row) {
        for (int col = 1; col < W; ++col) {
            if (grid[row][col] && !grid[row - 1][col]) {
                ++ans;
                while (grid[row][col] && !grid[row - 1][col]) ++col;
            }
        }
    }

    for (int row = 1; row < H; ++row) {
        for (int col = 1; col < W; ++col) {
            if (grid[row][col] && !grid[row + 1][col]) {
                ++ans;
                while (grid[row][col] && !grid[row + 1][col]) ++col;
            }
        }
    }

    cout << ans;
}
