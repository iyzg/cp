#include <bits/stdc++.h>

using namespace std;

int main() {
    // Literally fibo except broken stairs you just set to 0
    int N, M;
    cin >> N >> M;
    
    int current_broken = 0;
    long long int dp[N];
    int broken[M];
    for (int i = 0; i < M; i++)
    {
        cin >> broken[i];
    }

    dp[0] = 1;
    dp[1] = 2;
    
    for (int i = 0; i < 2; i++)
    {
        if (broken[i] - 1 == 0)
        {
            dp[0] = 0;
            dp[1] = 1;
            current_broken++;
        } else if (broken[i] - 1 == 1)
        {
            dp[1] = 0;
            current_broken++;
        }
    }

    for(int i = 2; i < N; i++)
    {
        if (i == broken[current_broken] - 1)
        {
            dp[i] = 0;
            current_broken++;
        } else {
            dp[i] = (((dp[i - 2] % 1000000007) + (dp[i - 1] % 1000000007)) % 1000000007);
        }
    }

    cout << (long long int)(dp[N - 1] % 1000000007);
}
