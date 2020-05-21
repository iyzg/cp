#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, H;
    cin >> N >> K;

    char S[N];

    for (int i = 0; i < N; i++)
    {
        char t;
        cin >> t;
        S[i] = t;
    }
    
    H = 0;
    for (int i = 0; i < N; i++)
    {
        if ((i == 0 && S[i] == 'L') || (i == N - 1 && S[i] == 'R'))
        {
            continue;
        } else if (S[i] == 'L' && S[i - 1] == 'L') {
            H++;
        } else if (S[i] == 'R' && S[i + 1] == 'R') {
            H++;
        }
    }

    cout << min(N - 1, H + 2 * K);

}
