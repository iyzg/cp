#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    long long int first;
    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (s[i] == '7' || s[i] == '4')
        {
            first++;
        }
    }
    
    ostringstream os;
    os << first;
    string digits = os.str();
    for (string::size_type i = 0; i < digits.size(); i++)
    {
        if (digits[i] == '7' || digits[i] == '4')
        {
            continue;
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
