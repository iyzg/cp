#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int difficulties[n];
    for (int i = 0; i < n; i++)
    {
        cin >> difficulties[i];
    }

    // If the two numbers in the middle are the same, there is no valid answers. Else, it's the difference between the two in the middle, so you have to sort it first
    sort(difficulties, difficulties + n);

    int left_middle, right_middle;
    left_middle = difficulties[(n / 2) - 1];
    right_middle = difficulties[n / 2];

    if (left_middle == right_middle)
    {
        cout << 0;
    } else {
        cout << right_middle - left_middle;
    }
}
