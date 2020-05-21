#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    int dp[H][W][4];

    char input;
    for(int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            cin >> input;
            if (input == '#')
            {
                for (int i = 0; i < 4; i++)
                {
                    dp[r][c][i] = 0; 
                }
            } else {
                for (int i = 0; i < 4; i++)
                {
                    dp[r][c][i] = 1; 
                }
            }
        }
    }

    for(int side = 0; side < 4; side++)
    {
        if(side == 0)
        {
            for(int r = 1; r < H; r++)
            {
                for(int c = 0; c < W; c++)
                {
                    if (dp[r][c][0] != 0)
                    {
                        dp[r][c][0] += dp[r - 1][c][0];
                    }
                }
            }
        } else if (side == 1)
        {
            for(int r = 0; r < H; r++)
            {
                for(int c = W - 2; c >= 0; c--)
                {
                    if (dp[r][c][1] != 0)
                    {
                        dp[r][c][1] += dp[r][c + 1][1];
                    }
                }
            }
        } else if (side == 2) {
            for(int r = H - 2; r >= 0; r--)
            {
                for(int c = 0; c < W; c++)
                {
                    if (dp[r][c][2] != 0)
                    {
                        dp[r][c][2] += dp[r + 1][c][2];
                    }
                }
            }
        } else if (side == 3) {
            for (int r = 0; r < H; r++)
            {
                for (int c = 1; c < W; c++)
                {
                    if (dp[r][c][3] != 0)
                    {
                        dp[r][c][3] += dp[r][c - 1][3];
                    }
                }
            }
        }
    }

    int max = 0;
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            if (dp[r][c][0] + dp[r][c][1] + dp[r][c][2] + dp[r][c][3] > max)
            {
                max = dp[r][c][0] + dp[r][c][1] + dp[r][c][2] + dp[r][c][3];
            }
        }
    }

    cout << max - 3;
}
