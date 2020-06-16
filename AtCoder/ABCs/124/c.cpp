#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int first = 0, second = 0;
    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '1')
            {
                second++;
            } else {
                first++;
            }
        } else {
            if (s[i] == '0')
            {
                second++;
            } else {
                first++;
            }
        }
    }

    cout << min(first, second);
}
