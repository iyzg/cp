#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 1000;

int h, w, a, b;
int grid[MX][MX];
int r[MX], c[MX];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w >> a >> b;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < w; j++) {
            cout << (j < a);
        }
        cout << '\n';
    }

    for (int i = 0; i < h - b; i++) {
        for (int j = 0; j < w; j++) {
            cout << (j >= a);
        }
        cout << '\n';
    }
}

