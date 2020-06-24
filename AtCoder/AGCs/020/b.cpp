#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> k;
    vector<ll> a(k);
    for (auto& i : a) cin >> i;
    reverse(a.begin(), a.end());

    if (a[0] != 2) {
        cout << -1;
        return 0;
    }
    
    ll lb = 2, rb = 3;
    for (int i = 1; i < k; ++i) {
        ll nlb = a[i] * ceil((long double)lb / a[i]);
        ll nrb = a[i] * (rb / a[i]) + a[i] - 1;
        if (nlb > rb) {
            cout << -1;
            return 0;
        }
        lb = nlb, rb = nrb;
    }

    cout << lb << ' ' << rb;
}
