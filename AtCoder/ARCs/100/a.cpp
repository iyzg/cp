#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;

int n;
ll a[N], total;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= (i + 1);
        total += a[i];
    }
    sort(a, a + n);
    
    ll ldist = 0, rdist = 0;
    for (int i = 1; i < n; i++) rdist += a[i] - a[0];
    
    ll sadness = rdist;
    for (int i = 1; i < n; i++) {
        ldist += i * (a[i] - a[i - 1]);
        rdist -= (n - i) * (a[i] - a[i - 1]);
        // cout << i << ' ' << ldist << ' ' << rdist << '\n';
        sadness = min(sadness, ldist + rdist);
    }
    
    cout << sadness;
}

    
