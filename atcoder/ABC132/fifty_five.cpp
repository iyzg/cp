#include <bits/stdc++.h>

using namespace std;

int main() {
    char first, second;
    
    cin >> first >> second;

    char input;
    cin >> input;
    if (input == first)
    {
        cin >> input;
        if (input == second)
        {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else if (input == second) {
        cin >> input;
            if (input == first)
            {
                cout << "Yes";
            } else {
                cout << "No";
            }
    } else {
        cout << "No";
    }
}
