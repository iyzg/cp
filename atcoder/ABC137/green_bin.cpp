#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N;
    cin >> N;
    string strings[N];
    string input;
        
    getline(cin, input);

    for (int i = 0; i < N; i++)
    {
        getline(cin, input);
        strings[i] = input;
        sort(strings[i].begin(), strings[i].end());
    }

    sort(strings, strings + N);

    long long int in_a_row = 1, pairs = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (strings[i] == strings[i + 1])
        {
            pairs += in_a_row;
            in_a_row++;
        } else {
            in_a_row = 1;
        }
    }

    cout << pairs;
}
