#include <bits/stdc++.h>

using namespace std;

int main() {
    char S[3];
    
    char in;
    for (int i = 0; i < 3; i++)
    {
        cin >> in;
        S[i] = in;
    }

    int c = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> in;

        if (S[i] == in)
        {
            c++;
        }
    }

    cout << c;

}
