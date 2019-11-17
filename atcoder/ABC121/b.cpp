#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    int B[M];

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    int input, cell, ans = 0;
    for (int r = 0; r < N; r++)
    {
        cell = 0;
        for (int c = 0; c < M; c++)
        {
            cin >> input;
            cell += input * B[c];
        }

        if (cell + C > 0)
        {
            ans++;
        }
    }

    cout << ans;
}
