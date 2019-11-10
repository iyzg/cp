#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[N][3] = { 0 };
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

    int input;
    for (int row = 1; row < N; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            cin >> input;
            if (column == 0)
            {
                dp[row][column] = input + max(dp[row - 1][1], dp[row - 1][2]);
            } else if (column == 1)
            {
                dp[row][column] = input + max(dp[row - 1][0], dp[row - 1][2]);
            } else {
                dp[row][column] = input + max(dp[row - 1][0], dp[row - 1][1]);
            }
        }
    }

    cout << max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
}
