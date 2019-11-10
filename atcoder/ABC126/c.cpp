#include <bits/stdc++.h>

using namespace std;

int main() {
    long double N, K;
    cin >> N >> K;

    long double probability = 0;
    int side = 1;
    int flips = ceil(log2(K));
    while (flips > 0 && side <= N)
    {
        probability += (1 / N) * pow((long double)1 / 2, (long double)flips);
        side++;
        if (side * pow(2, flips - 1) >= K)
        {
            flips--;
        }
    }

    probability += (1 / N) * (long double)((N - side) + 1);
    cout.precision(12);
    cout << probability;
}
