#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    
    if (m == 1 && s == 0)
    {
        cout << "0 0";
        return 0;
    }
    if (s > m * 9 || s == 0)
    {
        cout << "-1 -1";
        return 0;
    } 

    int number[m] = { 1 };
    s--;

    int current_digit = m - 1;
    while (s > 0)
    {
        number[current_digit]++;
        s--;

        if (number[current_digit] == 9)
        {
            current_digit--;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << number[i];
    }
    cout << " ";
    if (number[m - 1] != 0)
    {
        sort(number, number + m, greater<int>());
    }

    for (int i = 0; i < m; i++)
    {
        cout << number[i];
    }

}
