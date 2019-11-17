#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool valid_center[n];

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        valid_center[a - 1] = valid_center[b - 1] = false;
    }
    
    int center;
    for (int i = 0; i < n; i++)
    {
        if (valid_center[i])
        {
            center = i;
            break;
        }
    }

    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i == center)
            continue;

        cout << center + 1 << " " << i + 1 << "\n";
    }
}
