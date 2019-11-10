#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int length = 0, max = 0;
    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
        {
            length = 1;
            i++;
            while(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
            {
                i++;
                length++;
            }
            
            i--;
            if (length > max)
            {
                max = length;
            }
        }
    }

    cout << max;
}
