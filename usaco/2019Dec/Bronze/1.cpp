#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n, in; cin >> k >> n;
    int place[n][k];
    for(int i = 0; i < k; i++)
    {
        for(int c = 0; c < n; c++)
        {
            cin >> in;
            place[in - 1][i] = c;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int cow = 0; cow < n; cow++)
        {
            if (cow == i) continue;

            bool consistent = true;
            for (int j = 0; j < k; j++)
            {
                if (place[i][j] < place[cow][j])
                {
                    consistent = false;
                    break;
                }
            }
            if (consistent) ++ans;
        }
    }
    cout << ans << "\n";
}
