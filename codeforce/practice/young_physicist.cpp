#include <bits/stdc++.h>

using namespace std;

int main() {
    int vector3[3] = { 0 };
    int n, input;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> input;
            vector3[j] += input;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (vector3[i] != 0)
        {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
}
