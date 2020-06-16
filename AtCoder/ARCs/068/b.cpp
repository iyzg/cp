#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
map<int, int> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        m[a]++;
    }

    int tot = 0;
    for (auto& i : m) {
        tot += i.second - 1;
    }
    cout << m.size() - (tot % 2);
}
