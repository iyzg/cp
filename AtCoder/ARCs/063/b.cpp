#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;
map<ll, ll, greater<ll>> cnt;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;

    ll mn = -1;
    for (auto i : a) {
        if (mn == -1 || i < mn) {
            mn = i;
        } else {
            ++cnt[i - mn];
        }
    }

    for (auto i : cnt) {
        cout << i.second;
        break;
    }
}
