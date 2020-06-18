#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max = 0, second = 0, input;
    int numbers[N];
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        numbers[i] = input;
        if (input > max) {
            max = input;
        } else if (input > second) {
            second = input;
        }
    } 

    for (int i = 0; i < N; i++)
    {
        if (numbers[i] == max) {
            cout << second << "\n";
        } else {
            cout << max << "\n";
        }
    }
}
