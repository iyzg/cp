#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), ans(n);
    for (auto& i : a) cin >> i;

    ll water = a[n - 1];
    for (int i = n - 2; i > 0; --i) {
        water = a[i] - water;
    }
    ans[0] = a[0] - water;
    for (int i = 0; i < n - 1; i++) {
        ll have = ans[i] / 2;
        ans[i + 1] = (a[i] - have) * 2;
    }
    for (auto& i : ans) cout << i << " ";
}
