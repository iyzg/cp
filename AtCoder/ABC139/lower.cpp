#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N, M = 0, H;
    cin >> N;
    
    long long int last = 0, row = 0;
    cin >> last;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> H;
        if (H <= last)
        {
            row++;
        } else {
            if (row > M) {
                M = row;
            }
            row = 0;
        }

        if (i == N - 2)
        {
            if (row > M) {
                M = row;
            }
        }
        
        last = H;
    }

    cout << M;
}
