#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, option;

ll cur[2], res[2];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    
    // Which is going to be negative
    for (int i = 0; i < n; ++i) {
        cur[0] += a[i], cur[1] += a[i];
        if (!(i % 2) && cur[0] >= 0) {
            res[0] += cur[0] + 1;
            cur[0] = -1;
        } else if (i % 2 && cur[0] <= 0) {
            res[0] += abs(cur[0] - 1);
            cur[0] = 1;
        }

        if (i % 2 && cur[1] >= 0) {
            res[1] += cur[1] + 1;
            cur[1] = -1;
        } else if (!(i % 2) && cur[1] <= 0) {
            res[1] += abs(cur[1] - 1);
            cur[1] = 1;
        }
    }

    cout << min(res[0], res[1]);
}
