#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    if (n % 2) {
        ll last = a[n / 2];
        ll dp[2] = { 0 };
        for (int i = 0; i < n / 2; i++) {
            dp[0] += abs(last - a[i]);
            last = a[i];
            dp[0] += abs(last - a[n - (i + 1)]);
            last = a[n - (i + 1)];
        }
        last = a[n / 2];
        for (int i = 0; i < n / 2; i++) {
            dp[1] += abs(last - a[n - (i + 1)]);
            last = a[n - (i + 1)];
            dp[1] += abs(last - a[i]);
            last = a[i];
        }
        ans = max(dp[0], dp[1]);
    } else {
        ll last = a[n / 2 - 1];
        for (int i = 0; i < n / 2; i++) {
            ans += abs(a[n - (i + 1)] - last);
            last = a[n - (i + 1)];
            if (i != n / 2 - 1) {
                ans += abs(a[i] - last);
                last = a[i];
            }
        }   
    }
    cout << ans;
}

