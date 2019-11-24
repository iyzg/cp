#include <bits/stdc++.h>

using namespace std;

int a[15], ans = 0;
int n;

void solve(int index, int sum)
{
    if (index >= n)
    {
        if (sum % 360 == 0) ans = 1;
        return;
    }

    solve(index + 1, sum + a[index]);
    solve(index + 1, sum - a[index]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }   

    solve(0, 0);
    
    if (ans) cout << "YES";
    else cout << "NO";
}
