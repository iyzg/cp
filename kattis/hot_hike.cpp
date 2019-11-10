#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int days[n];
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    int day = 0, max_temp = 51;
    for (int i = 0; i < n - 2; i++)
    {
        if (max(days[i], days[i + 2]) < max_temp)
        {
            day = i + 1;
            max_temp = max(days[i], days[i + 2]);
        }
    }

    cout << day << " " << max_temp;
}
