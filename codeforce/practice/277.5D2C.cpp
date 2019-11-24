#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, s; cin >> m >> s;
    int ts = s, ti = 0;
    if (m == 1 && s == 0)
    {
        cout << "0 0";
        return 0;
    } else if (s > m * 9 || s == 0)
    {
        cout << "-1 -1";
        return 0;
    } 

    int d[m] = { 1 };
    ts = s - 1;

    int curr = m - 1;
    while (ts > 0)
    {
        d[curr]++;
        ts--;

        if (d[curr] == 9)
        {
            curr--;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << d[i];
        d[i] = 0;
    }

    cout << " ";
    ts = s;
    while (ts != 0) {
        if (ts >= 9)
        {
            d[ti] = 9;
            ts -= 9;
            ti++;
        } else {
            d[ti] = ts;
            ts -= ts;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << d[i];
    }
}
