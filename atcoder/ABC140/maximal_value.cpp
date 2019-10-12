#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int A[N] = { 0 };

    int current = 0, last = 0;
    cin >> last;
    A[0] = last;
    A[1] = last;
    for (int i = 1; i < N - 1; i++) 
    {
        cin >> current;
        if (current < last) {
            A[i] = current;
        } else {
            A[i] = last;
        }

        if (i == N - 2) 
        {
            A[N - 1] = current;
        }

        last = current;
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }

    cout << sum;
}
