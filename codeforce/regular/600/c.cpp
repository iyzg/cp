#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    long long int sweets[n], coefficients[n];
    for (int i = 0; i < n; i++)
        cin >> sweets[i];

    sort(sweets, sweets + n);
    
    for (int i = 0; i < n; i++)
        coefficients[i] = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        coefficients[i%m] += sweets[i];
        answer += coefficients[i%m];
        cout << answer << " ";
    }
}
