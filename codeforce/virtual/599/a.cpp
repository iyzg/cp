#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    cin >> k;

    for (int t = 0; t < k; t++)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);
        int side = 0, plank = n - 1;
        while (plank >= 0 && side < n)
        {
            if (a[plank] >= side + 1)
            {
                side++;
                plank--;
            } else {
                break;
            }
        }

        cout << side << "\n";
    }
}
