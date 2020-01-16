#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    int F = 0;

    cin >> N >> K;
        
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x >= K) {
            F++;
        }
    }

    cout << F;
}
