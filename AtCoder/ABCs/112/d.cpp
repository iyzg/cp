#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    ll ans = 1;
    for (ll i = 1; i * i <= m; i++) {
        if (!(m % i)) {
            if (i * n <= m) ans = max(ans, i);
            if (m / i * n <= m) ans = max(ans, m / i);
        }
    }   
    cout << ans;
}   
