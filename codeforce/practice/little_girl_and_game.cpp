#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int letters[26] = { 0 };
    for (int c = 0; c < (int)s.size(); c++)
    {
        letters[(int)s[c] - 97]++;
    }
 
    int turns = 0, first_odd, first_even; bool win;
    while (turns < (int)s.size())
    {
        win = true;
        first_odd = first_even = -1;
        for (int l = 0; l < 26; l++)
        {
            if (letters[l] % 2 == 1)
            {
                if (first_odd == -1)
                {
                    first_odd = l;
                } else {
                    win = false;
                    break;
                }
            } else if (letters[l] % 2 == 0 && first_even == -1 && letters[l] > 0) {
                first_even = l;
            }
        }

        if (win)
        {
            if (turns % 2 == 0)
            {
                cout << "First";
                break;
            } else {
                cout << "Second";
                break;
            }
        } else {
            if (first_even != -1)
            {
                letters[first_even]--;
            } else {
                letters[first_odd]--;
            }
        }
        turns++;
    }
}
