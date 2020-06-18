#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll ans, tot;

ll cnt[20];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
        for (int j = 0; j < 20; j++) {
            if (i & (1ll << j)) {
                cnt[j]++;
                tot++;
            }
        }
    }

    while (tot > 0) {
        ll cur = 0;
        for (int i = 0; i < 20; i++) {
            if (cnt[i]) {
                cur += (1ll << i);
                cnt[i]--;
                tot--;
            }
        }
        ans += powl(cur, 2);
    }

    cout << ans;
}
