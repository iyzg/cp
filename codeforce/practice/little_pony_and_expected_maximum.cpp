#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    long double probability = (long double)1 / ((double)pow(m, n));

    long long int difference = pow(2, n) - 2;
    long long int count = 1;
    long long int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += i * count;
        count += difference;
    }

    cout.precision(5);
    cout << (long double)sum * probability;
}
