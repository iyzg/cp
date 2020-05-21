#include <bits/stdc++.h>

using namespace std;

int main() {
    int dishes[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> dishes[i];
    }

    int wasted[5];
    for (int i = 0; i < 5; i++)
    {
        if (dishes[i] % 10 == 0)
        {
            wasted[i] = 0;
        } else {
            wasted[i] = 10 - (dishes[i] % 10);
        }
    }

    sort(wasted, wasted + 5);

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans += dishes[i] + wasted[i];
    }

    ans += dishes[4];
    cout << ans;
}
