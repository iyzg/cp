#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int N = 100;

int n;

int f[N][10], p[N][11];

ll ans = -INF;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> f[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> p[i][j];
        }
    }

    for (int i = 1; i < (1 << 10); i++) {
        int sim[n] = { 0 };
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (f[k][j]) sim[k]++;
                }
            }
        }

        ll cur = 0;
        for (int j = 0; j < n; ++j) cur += p[j][sim[j]];
        ans = max(ans, cur);
    }
    cout << ans;
}

