#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A <= 5)
    {
        cout << 0;
    } else if (A <= 12)
    {
        cout << B / 2;
    } else {
        cout << B;
    }
}
