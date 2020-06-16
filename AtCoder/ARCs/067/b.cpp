#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;
    vector<ll> x(n);
    for (auto& i : x) cin >> i;

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min((x[i] - x[i - 1]) * a, b);
    }
    cout << ans;
}
