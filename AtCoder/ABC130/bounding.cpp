#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X, bounces = 1, sum = 0, input;
    cin >> N >> X;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        sum += input;
        if (sum <= X)
        {
            bounces++;
        } else {
            break;
        }
    }
    
    cout << bounces;
}
