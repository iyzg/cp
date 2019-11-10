#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    long long int dp[N + 1][W + 1];
    long long int values[N];
    int weights[N];

    for (int r = 0; r < W + 1; r++)
    {
        dp[0][r] = 0;
    }

    for (int c = 0; c < N + 1; c++)
    {
        dp[c][0] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%i %lli", &weights[i], &values[i]);
    }

    for(int item = 1; item <= N; item++)
    {
        for(int capacity = 1; capacity <= W; capacity++)
        {
            long long int maxWithoutItem = dp[item - 1][capacity];
            long long int maxWithItem = 0;

            int weightOfItem = weights[item - 1];

            if (capacity >= weightOfItem)
            {
                maxWithItem = values[item - 1];
                int remainingCapacity = capacity - weightOfItem;
                maxWithItem += dp[item - 1][remainingCapacity];
            }

            dp[item][capacity] = max(maxWithoutItem, maxWithItem);
        }
    }

    cout << dp[N][W];
}
