#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, difference = 0; cin >> n;
    string result = "";
    int a[n], g[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> g[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (difference + a[i] <= 500)
        {
            result += 'A';
            difference += a[i];
        } else {
            result += 'G';
            difference -= g[i];
        }
    }

    if (difference > 500)
        cout << "-1";
    else 
        cout << result;
}
