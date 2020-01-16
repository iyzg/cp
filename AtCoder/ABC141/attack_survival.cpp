#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N, K, Q;
    cin >> N >> K >> Q;

    long long int players[N] = { 0 };

    int A = 0;
    for (int i = 0; i < Q; i++)
    {
        cin >> A;
        players[A - 1] = players[A - 1] + 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (Q - players[i] < K)
        {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}

