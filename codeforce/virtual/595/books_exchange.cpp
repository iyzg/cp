#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int current_query = 0; current_query < q; current_query++)
    {
        int n;
        cin >> n;

        int permutation[n];
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> permutation[i];
        }
        
        int cycle = 1, current_kid = 0;
        vector<int> indecies_in_cycle;
        for (int i = 0; i < n; i++)
        {   
            if (visited[i] == true)
            {
                continue;
            }

            cycle = 1;
            current_kid = i;
            while (permutation[current_kid] != i + 1)
            {
                current_kid = permutation[current_kid] - 1;
                indecies_in_cycle.push_back(current_kid);
                visited[current_kid] = true;
                cycle++;
            }

            permutation[i] = cycle;

            for(int j = 1; j < cycle; j++)
            {
                permutation[indecies_in_cycle[j - 1]] = cycle;
            }
                
            indecies_in_cycle.clear();
        }
    

        for (int k = 0; k < n; k++)
        {
            cout << permutation[k] << " ";
        }
        cout << "\n";
    }
}
