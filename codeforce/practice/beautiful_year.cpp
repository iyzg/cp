#include <bits/stdc++.h>

using namespace std;

int main() {
    int year, temp;
    bool beautiful = false;
    
    cin >> year;
    year++;
    int digits[4];
    while (!beautiful)
    {
        temp = year;
        beautiful = true;
        for (int i = 0; i < 4; i++)
        {
            digits[i] = temp % 10;
            temp = temp / 10;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (digits[j] == digits[i])
                {
                    beautiful = false;
                    continue;
                }
            }

            if (!beautiful)
            {
                continue;
            }
        }
        
        if (!beautiful)
        {
            year++;
        }
    }

    cout << year;
}
