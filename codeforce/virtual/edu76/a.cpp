#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, x, a, b;
    cin >> t;
    
    for (int test = 0; test < t; test++)
    {
        cin >> n >> x >> a >> b;
        cout << min(abs(b - a) + x, n - 1) << "\n";
    }
}
