#include <bits/stdc++.h>

using namespace std;

int a[1001];

int main() {
    int n, m, k, ans = 0; cin >> n >> m >> k;
    for (int i = 0; i < m + 1; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i)
    {
        int d = 0;
        for (int j = 0; j < n; j++) d += (a[i] >> j & 1) != (a[m] >> j & 1);
        ans += d <= k;
    }

    cout << ans;

}
