#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    for (int t = 0; t < k; t++)
    {
        int n;
        cin >> n;
        
        string one, two;
        getline(cin, one); // Read newline
        getline(cin, one);
        getline(cin, two);

        char distinct[2];
        bool diff = false, fixed = false;

        for (int i = 0; i < n; i++)
        {
            if (one[i] != two[i])
            {
                if (!diff)
                {
                    diff = true;
                    distinct[0] = one[i];
                    distinct[1] = two[i];
                } else {
                    if (!fixed)
                    {
                        if ((distinct[0] == two[i] && distinct[1] == one[i]) || (distinct[0] == one[i] && distinct[1] == two[i]))
                        {
                            fixed = true;
                        } else {
                            fixed = false;
                            break;
                        }
                    } else {
                        fixed = false;
                        break;
                    }
                }
            }
        }

        if (fixed)
        {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}
