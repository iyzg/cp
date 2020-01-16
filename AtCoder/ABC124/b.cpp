#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 1, max;
    cin >> max;
    int input;
    for (int i = 1; i < n; i++)
    {
        cin >> input;
        if (input >= max)
        {
            ans++;
            max = input;
        }
    }

    cout << ans;
}
