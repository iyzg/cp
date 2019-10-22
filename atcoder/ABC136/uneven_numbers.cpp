#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int number = 0;

    if (N > 9) {
        number += 9;
    } else {
        cout << N;
        return 0;
    }

    if (N > 999) {
        number += 900;
    } else {
        cout << number + max(0, N - 100 + 1);
        return 0;
    }

    if (N > 99999) {
        number += 90000;
    } else {
        cout << number + max(0, N - 10000 + 1);
        return 0;
    }

    cout << number;
}
