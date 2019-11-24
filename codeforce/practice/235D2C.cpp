#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if (m > n * 2 + 2 || n > m + 1)
        cout << -1;
    else 
    {
        if (n > m)
        {
            for (int i = 0; i < m; i++)
            {
                cout << "01";
            }
            cout << 0;
        } else if (n == m) {
            for (int i = 0; i < n; i++)
            {
                cout << "10";
            }
        } else {
            while (m >= 1) {
                if (m == n)
                {
                    cout << "10";
                    m--;
                    n--;
                } else {
                    if (m > 2) {
                        cout << "11";
                        m -= 2;
                    } else {
                        cout << "1";
                        m--;
                    }

                    if (n > 0)
                    {
                        n--;
                        cout << "0";
                    }
                }
            }
        }
    }
}
