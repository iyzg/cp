#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        long long int x, y; cin >> x >> y;
        if (x >= y || x >= 4)
        {
            cout << "YES\n";
            continue;
        }
    
        if (x % 2 == 1)
        {
            cout << "NO\n";
            continue;
        } else {
            if (x * 3 / 2 >= y)
            {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
