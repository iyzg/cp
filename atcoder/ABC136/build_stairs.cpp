#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long int H, max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> H;

        if (H > max)
        {
            max = H;
        } else if (H < max - 1) {
            cout << "No";
            return 0;
        } 
    }

    cout << "Yes";
}
