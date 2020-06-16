#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x, ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i - 1] > x) {
            int eat = min(a[i], a[i] + a[i - 1] - x);
            a[i] -= eat;
            ans += eat;
        }
    }
    if (a[0] + a[1] > x) {
        ans += a[0] + a[1] - x;
    }
    cout << ans;
}


