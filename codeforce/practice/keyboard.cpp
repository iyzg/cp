#include <bits/stdc++.h>

using namespace std;

int main() {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char characters[30];
    copy(keyboard.begin(), keyboard.end(), characters);
    char shift;
    cin >> shift;
    if (shift == 'L')
    {
        char input;
        while (cin >> input) {
            for (int i = 0; i < 30; i++)
            {
                if (input == characters[i])
                {
                    cout << characters[i + 1];
                }
            }
        }
    } else {
        char input;
        while (cin >> input) {
            for (int i = 0; i < 30; i++)
            {
                if (input == characters[i])
                {
                    cout << characters[i - 1];
                }
            }
        }

    }
}
