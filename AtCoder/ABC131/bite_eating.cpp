#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int sum = 0;
    for (int i = 1; i < N + 1; i++)
    {
        sum += (i + L) - 1;
    }
    if (L >= 0)
    {
        sum -= (1 + L) - 1;
    } else if (N + (L - 1) < 0)
    {
        sum -= (N + L) - 1;
    }
    cout << sum;
}
