#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int cosmic_table[n][m];
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cin >> cosmic_table[r][c];
        }
    }
        
    char query; int first, second;
    for(int i = 0; i < k; i++)
    {
        cin >> query >> first >> second;
        if (query == 'c')
        {
            for (int r = 0; r < n; r++)
            {
                int temp = cosmic_table[r][first - 1];
                cosmic_table[r][first - 1] = cosmic_table[r][second - 1];
                cosmic_table[r][second - 1] = temp;
            }
        } else if (query == 'r')
        {
            for (int c = 0; c < m; c++)
            {
                int temp = cosmic_table[first - 1][c];
                cosmic_table[first - 1][c] = cosmic_table[second - 1][c];
                cosmic_table[second - 1][c] = temp;
            }
        } else {
            cout << cosmic_table[first - 1][second - 1] << "\n";
        }
    }

}
