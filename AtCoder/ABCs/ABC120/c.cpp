#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int blue = 0, red = 0;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '0')
        {
            red++;
        } else {
            blue++;
        }
    }       

    cout << min(red, blue) * 2;
}
