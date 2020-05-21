#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int net[N];

    for(int i = 0; i < N; i++)
    {
        cin >> net[i];
    }
    
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        net[i] -= input;
    }

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (net[i] > 0)
        {
            max += net[i];
        }
    }

    cout << max;
}
