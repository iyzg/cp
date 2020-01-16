#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    int range = D * 2 + 1;
    int inspectors = 0;
    while (range * inspectors < N)
    {
        inspectors++;
    }

    cout << inspectors;
}
