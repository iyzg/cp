#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; 
    cin >> N;

    double values[N];
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        values[i] = temp;
    }

    sort(values, values + N);

    for (int i = 1; i < N; i++)
    {
        values[i] = (values[i] + values[i - 1]) / 2;
    }

    cout << values[N - 1];
}
