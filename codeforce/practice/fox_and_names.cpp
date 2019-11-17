#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    bitset<26> available;
    available.set();
    char last;
    string name, order = "";
    getline(cin, name);
    bool impossible = false;
    for (int i = 0; i < n; i++)
    {
        getline(cin, name);
        if (available[(int)name[0] - 97])
        {
            available[(int)name[0] - 97] = 0;
            order += name[0];
            last = name[0];
        } else if (last == name[0]) {
            continue;
        } else {
            impossible = true;
            break;
        }
    }
    
    if (impossible)
    {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < (int)order.size(); i++)
        cout << order[i];

    for (int i = 0; i < 26; i++)
        if (available[i])
            cout << (char)(i + 97);
}
