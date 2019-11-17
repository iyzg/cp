#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    if (s.size() == 1)
    {
        cout << s;
        return 0;
    }

    for (string::size_type i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            s[i] = s[i + 1] = s[i + 2] = '-';
            i += 2;
        } 
    }

    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            cout << " ";
            while (s[i] == '-')
            {
                i++;
            }
            i--;
        } else {
            cout << s[i];
        }
    }
}
