#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, current_min;
    cin >> N >> K;

    int heights[N];
    int dp[N] = { 0 };
    
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < N; i++)
    {
        current_min = abs(heights[i] - heights[i - 1]) + dp[i - 1];

        for (int j = 2; j <= K && i - j >= 0; j++)
        {
            current_min = min(current_min, abs(heights[i] - heights[i - j]) + dp[i - j]);
        }
    
        dp[i] = current_min;
    }

    cout << dp[N - 1];
}
