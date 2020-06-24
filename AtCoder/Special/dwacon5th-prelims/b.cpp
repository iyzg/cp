#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
ll cnt[45];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    
    multiset<ll> val;
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            for (int l = 0; l < 45; ++l) {
                if (sum & (1ll << l)) ++cnt[l];
            }
            val.insert(sum);
        }
    }
    
    ll taken = 0, tot = 0;
    for (int i = 44; i >= 0; --i) {
        // cout << i << ' ' << cnt[i] << '\n';
        // if (taken == k) break;
        if (cnt[i] >= k) {
            ++taken;
            tot += (1ll << i);

            auto it = val.begin();
            while (it != val.end()) {
                if (!(*it & (1ll << i))) {
                    for (int j = 0; j < 45; ++j) {
                        if (*it & (1ll << j)) 
                            --cnt[j];
                    }
                    it = val.erase(it);
                } else ++it;
            }
        }
    }
    cout << tot;
}
