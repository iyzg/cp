#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n;
ll conn[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    for (auto& i : c) cin >> i;
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    
    int r = 0;
    for (int i = 0; i < n; i++) {
        while (r < n && c[r] > b[i]) r++;
        conn[i] = r;
    }

    r = 0;
    ll pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (r < n && b[r] > a[i]) {
            pref += conn[r];
            r++;
        }
        ans += pref;
    }
    cout << ans;
}
    

