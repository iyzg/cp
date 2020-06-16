#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n;
ll dp[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int x = 1; i - (int)(pow(6, x) + 0.5) >= 0; x++) {
            dp[i] = min(dp[i], dp[i - (int)(pow(6, x) + 0.5)] + 1);
        }

        for (int x = 1; i - (int)(pow(9, x) + 0.5) >= 0; x++) {
            dp[i] = min(dp[i], dp[i - (int)(pow(9, x) + 0.5)] + 1);
        }
    }

    cout << dp[n];
}

