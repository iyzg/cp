#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& i : a) cin >> i.first >> i.second;

    ll tv = a[0].first, av = a[0].second;
    for (ll i = 1; i < n; ++i) {
        ll tt = ceil((long double)tv / a[i].first), at = ceil((long double)av / a[i].second);
        ll times = max(tt, at);
        tv = a[i].first * times, av = a[i].second * times;
    }

    cout << tv + av;
}
