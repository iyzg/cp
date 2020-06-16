#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for (int b = k + 1; b <= n; ++b) {
        if (b == 1) {
            ans++;
            continue;
        }

        ans += (n / b) * (b - k);
        ans += max(0, n % b - k + 1);
    }

    cout << ans;
}

