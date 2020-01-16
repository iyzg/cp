#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int stones[n];
    int dp[n] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    
    dp[1] = abs(stones[1] - stones[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(abs(stones[i] - stones[i - 1]) + dp[i - 1], abs(stones[i] - stones[i - 2]) + dp[i - 2]);
    }

    cout << dp[n - 1];
}
