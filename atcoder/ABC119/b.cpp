#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    long double amount = 0;
    long double received; string currency;
    for (int i = 0; i < N; i++)
    {
        cin >> received >> currency;
        if (currency == "JPY")
        {
            amount += received;
        } else {
            amount += (received * 380000);
        }
    }
    
    cout.precision(10);
    cout << amount;
}
