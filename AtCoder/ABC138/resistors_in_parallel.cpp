#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    double total = 0;
    double input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        total += (1/input);
    }

    cout << (1/total);
}
