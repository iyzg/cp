#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int permutation[N];
    long long int ways[K] = { 0 };

    // Adds the blue balls in as 0 and the red balls in as 1
    for (int i = 0; i < N; i++)
    {
        if (i < K) {
            permutation[i] = 0;
        } else {
            permutation[i] = 1;
        }
    }

    do {
        long long int found = 0;
        for(int i = 0; i < N; i++)
        {
            if (permutation[i] == 0)   
            {
                found += 1;
                while (permutation[i] == 0)
                {
                    i++;
                }
            }
        }

        ways[found - 1]++;
    } while(next_permutation(permutation, permutation + N));

    for (int i = 0; i < K; i++)
    {
        cout << ways[i] << "\n";
    }
}
