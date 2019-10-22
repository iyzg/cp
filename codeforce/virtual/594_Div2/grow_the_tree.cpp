#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lengths[n];
    for (int i = 0; i < n; i++)
    {
        cin >> lengths[i];
    }

    sort(lengths, lengths + n);
    long long int height = 0, length = 0;
    for (int i = 0; i < n / 2; i++)
    {
        height += lengths[i];
    }

    for (int i = n / 2; i < n; i++)
    {
        length += lengths[i];
    }

    cout << (long long)(pow(height, (long long) 2) + pow(length, (long long)2));
}
