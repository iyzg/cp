#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    if (a > b) swap(a, b);
    ll moves = 0;
    while (b <= n) {
        ll tmp = b;
        b = a + b;
        a = tmp;
        moves++;
    }
    cout << moves << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
