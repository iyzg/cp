#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int lower = 0, upper = 0;
    for (string::size_type i = 0; i < s.size(); i++)
    {
        if (islower(s[i]))
        {
            lower++;
        } else {
            upper++;
        }
    }

    if (lower >= upper)
    {
        for (string::size_type i = 0; i < s.size(); i++)
        {
            putchar(tolower(s[i]));
        }
    } else {
        for (string::size_type i = 0; i < s.size(); i++)
        {
            putchar(toupper(s[i]));
        }
    }
}
