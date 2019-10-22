#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int permutation[N];
    int input;
    for (int i = 0; i < N; i++)
    {   
        cin >> input;
        permutation[i] = input;
    }
    
    bool swapped = false;
    for (int i = 0; i < N; i++)
    {
        if (permutation[i] != i + 1)
        {
            if (permutation[permutation[i] - 1] == i + 1 && !swapped)
            {
                swapped = true;
                int temp = permutation[i];
                permutation[permutation[i] - 1] = temp;
                permutation[i] = i + 1;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}
