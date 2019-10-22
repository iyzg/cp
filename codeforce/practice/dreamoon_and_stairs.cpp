#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n < m)
    {
        cout << -1;
        return 0;
    }

    for (int i = (n / 2) + 1; i < n; i++)
    {
        if (i % m == 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}

