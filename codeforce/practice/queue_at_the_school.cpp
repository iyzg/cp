#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    char line[n];
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
    }

    for (int i = 0; i < t; i++)
    {
        for(int child = 0; child < n - 1;)
        {
            if (line[child] == 'B' && line[child + 1] == 'G')
            {
                line[child] = 'G';
                line[child + 1] = 'B';
                child += 2;
            } else {
                child += 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << line[i];
    }
}
