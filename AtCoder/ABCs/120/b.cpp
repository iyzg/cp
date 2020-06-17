#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<int> factors;
    for (int i = 1; i <= min(A, B); i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            factors.push_back(i);
        }
    }

    cout << factors[factors.size() - K];
}
