#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int ki = 2;
    while (ki * (ki - 1) <= 2 * n) {
        if (2 * n == ki * (ki - 1)) {
            k = ki;
            break;
        }
        ++ki;
    }
    
    if (!k) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    cout << k << '\n';

    // Start numbers are 1 - k - 1
    // Then you want to distribute from k -> n evenly so that none are repeated

    vector<int> past;
    int known = 1;
    for (int i = 0; i < k; ++i) {
        cout << k - 1 << ' ';
        for (auto& j : past)
            cout << j++ << ' ';

        if (k - 1 - past.size()) {
            past.push_back(known);
            for (int j = 0; j < k - past.size(); ++j) 
                cout << known++ << ' ';
        }
        cout << '\n';
    }
}
