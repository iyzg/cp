#include <bits/stdc++.h>

using namespace std;

void print_each_digit(int x)
{
    if(x >= 10)
       print_each_digit(x / 10);

    int digit = x % 10;

    std::cout << digit << '\n';
}

int main() {
    int number;
    cin >> number;

    int digits[4];
    for(int i = 0; i < 4; i++)
    {
        digits[i] = number % 10;
        number = number / 10;
    }

    for (int i = 0; i < 3; i++)
    {
        if(digits[i] == digits[i + 1])
        {
            cout << "Bad";
            return 0;
        }
    }
    cout << "Good";
}
