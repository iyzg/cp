#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n; cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int difference = 0;
        bool used = false, possible = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                possible = false;
                break;
            } else if (a[i] == b[i]) {
                continue;
            } else {
                if (used)
                {
                    possible = false;
                    break;
                }

                difference = b[i] - a[i];
                while (i < n)
                {
                    if (b[i] - a[i] == difference)
                    {
                        i++;
                        continue;
                    }
                    if (b[i] == a[i])
                    {
                        used = true;
                        break;
                    }
                    if (b[i] - a[i] != difference)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}
