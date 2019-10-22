#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string strings[N];

    string input;
    getline(cin, input);
    for (int i = 0; i < N; i++)
    {
        getline(cin, strings[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (strings[i].length() <= 10)
        {
            cout << strings[i] << "\n";
        } else {
            cout << strings[i][0] << strings[i].length() - 2 << strings[i][strings[i].length() - 1] << "\n";
        }
    }
}

