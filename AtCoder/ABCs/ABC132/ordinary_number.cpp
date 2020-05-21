#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int permutation[n];
    for(int i = 0; i < n; i++)
    {
        cin >> permutation[i];
    }

    int num = 0;
    for(int i = 1; i < n - 1; i++)
    {
        if ((permutation[i - 1] < permutation[i] && permutation[i] < permutation[i + 1]) || (permutation [i - 1] > permutation[i] && permutation[i] > permutation[i + 1]))
        {
            num++;
        }
    }

    cout << num;
}
