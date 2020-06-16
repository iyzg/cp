#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N], B[N], C[N - 1];

    int t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        A[i] = t;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> t;
        B[i] = t;
    }
    
    for (int i = 0; i < N - 1; i++)
    {
        cin >> t;
        C[i] = t;
    }

    int points = 0;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && A[i] == A[i - 1] + 1)
        {
            points += B[A[i] - 1] + C[A[i - 1] - 1];
        } else {
            points += B[A[i] - 1];
        }
    }

    cout << points;
}
