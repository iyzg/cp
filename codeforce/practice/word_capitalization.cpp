#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    putchar(toupper(s[0]));
    for(string::size_type i = 1; i < s.size(); i++)
    {
        cout << s[i];
    }
}
