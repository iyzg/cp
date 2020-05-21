#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, D;
    long long int X, pX;
    cin >> R >> D >> X;

    pX = X;
    for (int i = 1; i <= 10; i++)
    {
        X = (R * pX) - D;
        cout << X << "\n";
        pX = X;
    }
}
