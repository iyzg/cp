#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 45, N = 100005;
 
ll n, k;
ll t[MX], dt[MX], opt[MX];
ll ans;
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a) {
        cin >> i;
        ans += i;
        for (int j = 0; j < MX; ++j) {
            if (!((1ll << j) & i)) {
                t[j] += (1ll << j);
            } else dt[j] += (1ll << j);
        }
    }

    for (int i = 0; i < MX; ++i) opt[i] = max(t[i], dt[i]);
    
    int lm = -1;
    for (int i = MX - 1; i >= 0; --i) {
        if ((1ll << i) & k) lm = i;
        else {
            if (lm == -1) continue;
            dt[lm] += opt[i];
            t[lm] += dt[i];
            opt[lm] += opt[i];
        }
    }
 
    ll tmp = 0;
    bool lower = false;
    for (int i = MX - 1; i >= 0; --i) {
        if ((1ll << i) > k) tmp += dt[i]; 
    
        if ((1ll << i) & k) {
            if (lower) {
                tmp += opt[i];
            } else if (dt[i] >= t[i]) {
                lower = true;
                tmp += dt[i];
            } else tmp += t[i];
        }
        // cout << i << ' ' << tmp << '\n';
    }
    
    cout << max(tmp, ans);
}
