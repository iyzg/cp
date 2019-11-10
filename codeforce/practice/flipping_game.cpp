#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int array[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        if (array[i] == 0)
        {
            dp[i] = 1;
        } else {
            dp[i] = -1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (dp[i] < dp[i - 1] + dp[i]) {
            dp[i] = dp[i - 1] + dp[i];
        }
    }
        
    int end_index = 0, temp_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > temp_max)
        {
            end_index = i;
            temp_max = dp[i];
        }
    }
    
    if (dp[end_index] == -1)
    {
        if (array[end_index] == 0)
        {
            array[end_index] = 1;
        } else {
            array[end_index] = 0;
        }

    } else {
        while (dp[end_index] != -1)
        {
            if (array[end_index] == 0)
            {
                array[end_index] = 1;
            } else {
                array[end_index] = 0;
            }

            end_index--;
        }
    }
    

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            max++;
        }
    }

    cout << max;
}
