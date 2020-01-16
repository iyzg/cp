#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    int points[N][D];

    for (int point = 0; point < N; point++)
    {
        for (int dimension = 0; dimension < D; dimension++)
        {
            cin >> points[point][dimension];
        }
    }
    
    int valid_combos = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int before_sqrt = 0;
            for(int d = 0; d < D; d++)
            {
                before_sqrt += pow(abs(points[i][d] - points[j][d]), 2);
            }

            long double sr = sqrt(before_sqrt);
            if (sr - floor(sr) == 0)
            {
                valid_combos++;
            }
        }
    }

    cout << valid_combos;
}
