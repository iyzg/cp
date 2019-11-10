#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    long long int dls_even, dls_odd, jls_even, jls_odd;
    int n, m;
    for (int i = 0; i < t; i++)
    {
        dls_even = 0;
        dls_odd = 0;
        jls_even = 0;
        jls_odd = 0;


        cin >> n;
        long long int p;
        for (int dls_times = 0; dls_times < n; dls_times++)
        {
            cin >> p;
            if (p % 2 == 0)
            {
                dls_even++;
            } else {
                dls_odd++;
            }
        }


        cin >> m;
        long long int q;
        for (int jls_times = 0; jls_times < m; jls_times++)
        {
            cin >> q;
            if (q % 2 == 0)
            {
                jls_even++;
            } else {
                jls_odd++;
            }
        }
        
        cout << (dls_even * jls_even) + (dls_odd * jls_odd) << "\n";
    }
}
