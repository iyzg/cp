#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (B == 1) 
    {
        cout << 0;
    } else if (B <= A) {
        cout << 1;
    } else {
        int N = 1;
        int S = A;
        while (S < B)
        {
            N++;
            S += A - 1;
        }
        
        cout << N;
    }
}
