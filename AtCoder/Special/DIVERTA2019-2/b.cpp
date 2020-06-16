#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

map<pair<ll, ll>, ll> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll y = a[j].second - a[i].second;
            ll x = a[j].first - a[i].first;
            m[{x, y}]++;
        }
    }
    
    ll ans = 0;
    for (auto& i : m) {
        ans = max(ans, i.second);
    }
    cout << n - ans;    
}   
