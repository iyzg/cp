#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    if (k > a[n - 1]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    ll gcd = a[0];
    for (int i = 1; i < n; ++i) {
        gcd = __gcd(gcd, a[i]);
        gcd = __gcd(gcd, a[i] - a[i - 1]);
    }

    if (k % gcd) {
        cout << "IMPOSSIBLE";
    } else {
        cout << "POSSIBLE";
    }
}
