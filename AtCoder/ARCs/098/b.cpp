#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;

    for (int l = 0, r = 0, cur = 0, lr = 0; r < n; ++r) {
        while (l < r && (cur & a[r]) != 0) {
            cur ^= a[l];
            ++l;
        }

        bool moved = false;
        while (r < n && (cur & a[r]) == 0) {
            cur ^= a[r];
            ++r;
            moved = true;
        }

        ll sz = r - l;
        // cout << l << ' ' << r << '\n';
        ll rep = max(0, lr - l);
        ans -= rep * (rep - 1) / 2;
        ans += sz * (sz - 1) / 2;
        lr = r;
        if (moved) --r;
    }
    
    ans += n;
    cout << ans;
}

