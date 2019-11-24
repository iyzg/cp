#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++)
    {
        long long int a, b, n, s; cin >> a >> b >> n >> s;
        if (a * n + b < s)
        {
            cout << "NO\n";
        } else {
            long long int large_needed = s / n;
            if (min(large_needed, a) * n + b >= s)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }
}
