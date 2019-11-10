#include <bits/stdc++.h>

using namespace std;

int main() {
    int input;
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            cin >> input;
            if (input == 1)
            {
                cout << abs(row - 2) + abs(column - 2);
            }
        }
    }
}
