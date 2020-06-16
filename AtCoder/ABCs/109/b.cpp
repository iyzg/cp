#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
map<string, int> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
        m[i]++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i][0] != a[i - 1][a[i - 1].size() - 1]) {
            cout << "No";
            return 0;
        }
    }

    for (auto& i : m) {
        if (i.second > 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}

