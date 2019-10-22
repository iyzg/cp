#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long int monsters[N + 1];
    long long int heroes[N];

    long long int input;
    for (int i = 0; i < N + 1; i++)
    {   
        cin >> input;
        monsters[i] = input;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        heroes[i] = input;
    }

    long long int defeated = 0;
    for (int i = 0; i < N; i++)
    {
        if (heroes[i] <= monsters[i]) {
            defeated += heroes[i];
        } else {
            defeated += monsters[i];
            long long int leftover = heroes[i] - monsters[i];
            defeated += min(leftover, monsters[i + 1]);
            monsters[i + 1] = max(monsters[i + 1] - leftover, (long long) 0);
        }
    }

    cout << defeated;
}
