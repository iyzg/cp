#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int weights[N];
    for(int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }

    int left_sum = 0, right_sum = weights[N - 1], smallest = 1000000;
    for(int i = 0; i < N - 1; i++)
    {
        left_sum += weights[i];
    }
    if (abs(left_sum - right_sum) < smallest)
    {
        smallest = abs(left_sum - right_sum);
    }

    for(int i = N - 2; i >= 0; i--)
    {
        left_sum -= weights[i];
        right_sum += weights[i];
        if (abs(left_sum - right_sum) < smallest)
        {
            smallest = abs(left_sum - right_sum);
        }
    }

    cout << smallest;
}
