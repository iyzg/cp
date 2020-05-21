#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    char input;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        if (i == k)
        {
            input = putchar(tolower(input));
        } else {
            cout << input;

        }
        
    }
}
