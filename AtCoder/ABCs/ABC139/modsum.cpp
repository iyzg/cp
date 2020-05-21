#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N;
    cin >> N;
    
    long long int total = 0;
    for (int i = 1; i < N; i++)
    {
        total += i;
    }

    cout << total;
}
