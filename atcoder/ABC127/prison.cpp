#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int left, right, tight_left = 0, tight_right = N;
    for(int i = 1; i <= M; i++)
    {
        cin >> left >> right;

        if (right < tight_left || left > tight_right)
        {
            cout << 0;
            return 0;
        }

        if (left > tight_left)
        {
            tight_left = left;
        } 
        if (right < tight_right)
        {
            tight_right = right;
        }
    }

    cout << tight_right - tight_left + 1;
}
