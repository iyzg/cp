#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> i_i;

const int MX = 100;

int a, b;
int grid[MX][MX], req[2];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> req[0] >> req[1];
    --req[0], --req[1];
    
    cout << "100 100\n";
    for (int i = 50; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            grid[i][j] = 1;
        }
    }

    for (int i = 0; i < 49; i += 2) {
        for (int j = 0; j < MX; j += 2) {
            if (req[1]) {
                grid[i][j] = 1;
                --req[1];
            }
        }
    }

    for (int i = 51; i < MX; i += 2) {
        for (int j = 0; j < MX; j += 2) {
            if (req[0]) {
                grid[i][j] = 0;
                --req[0];
            }
        }
    }

    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < MX; ++j) {
            if (grid[i][j]) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}
