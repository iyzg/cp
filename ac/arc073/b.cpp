#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, w, ans;

map<ll, ll, greater<ll>> m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    vector<pair<ll, ll>> a(n);
    for (auto& i : a) cin >> i.first >> i.second;

    for (auto i : a) {
        for (auto c : m) {
            int nw = i.first + c.first;
            if (nw <= w) {
                m[nw] = max(m[nw], c.second + i.second);
                ans = max(ans, m[nw]);
            }
        }
        m[i.first] = max(m[i.first], i.second);
        if (i.first <= w) ans = max(ans, m[i.first]);
    }
    
    cout << ans;
}
