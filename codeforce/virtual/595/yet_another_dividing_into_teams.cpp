#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;

        int skills[n];
        for (int j = 0; j < n; j++)
        {
            cin >> skills[j];
        }

        sort(skills, skills + n);
        
        bool two_needed = false;
        for (int k = 1; k < n; k++)
        {
            if (skills[k] - skills[k - 1] == 1)
            {
                two_needed = true;
                cout << 2 << "\n";
                break;
            }
        }

        if (!two_needed)
        {
            cout << 1 << "\n";
        }
    }
}
