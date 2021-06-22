#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 1005;

int forest[MX][MX];

struct BIT {
    int size;
    vector<vector<int>> grid;

    void init(int n) {
        size = n;
        grid.assign(n + 1, vector<int>(n + 1, 0));
    }

    void update(int x, int y, int v) {
        while (x <= size) {
            updatey(x, y, v);
            x += (x & -x);
        }
    }

    void updatey(int x, int y, int v) {
        while (y <= size) {
            grid[x][y] += v;
            y += (y & -y);
        }
    }

    int query(int x, int y) {
        int sum = 0;
        while (x > 0) {
            sum += queryy(x, y);
            x -= (x & -x);
        }

        return sum;
    }

    int queryy(int x, int y) {
        int sum = 0;
        while (y > 0) {
            sum += grid[x][y];
            y -= (y & -y);
        }

        return sum;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    BIT bt;
    bt.init(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            forest[i][j] = (c == '*');
            bt.update(i + 1, j + 1, forest[i][j]);
        }
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int y, x; cin >> y >> x;
            forest[y - 1][x - 1] = !forest[y - 1][x - 1];
            if (!forest[y - 1][x - 1]) bt.update(y, x, -1);
            else bt.update(y, x, 1);
        } else {
            int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
            cout << bt.query(y2, x2) - bt.query(y2, x1 - 1) - bt.query(y1 - 1, x2) + bt.query(y1 - 1, x1 - 1) << '\n';
        }
    }
}
