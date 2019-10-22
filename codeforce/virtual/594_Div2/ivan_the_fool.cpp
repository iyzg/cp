#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;
    cout << ((long long)pow(n, m)) % ((long long)pow(10, 9) + 7);
}
