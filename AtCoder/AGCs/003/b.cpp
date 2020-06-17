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
    
    for (int i = 0; i < n; i++) {
        if (!a[i]) continue;
        
        if (i < n - 1) {
            if (a[i] % 2 && a[i + 1]) {
                --a[i], --a[i + 1];
                ans += 1;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        ans += a[i] / 2;
    }

    cout << ans;
}

