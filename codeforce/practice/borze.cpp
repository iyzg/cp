#include <bits/stdc++.h>

using namespace std;

int main() {
    char input, second_input;
    while (cin >> input)
    {
        if (input == '.')
        {
            cout << "0";
        } else {
            cin >> second_input;
            if (second_input == '.')
            {
                cout << "1";
            } else {
                cout << "2";
            }
        }
    }
}
