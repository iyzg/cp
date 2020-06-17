#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n;
ll ans = 1, nodes;
ll l[N], r[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n + 1);
    for (auto& i : a) cin >> i;

    for (int i = n; i > 0; --i) {
        if (i == n) {
            l[i] = r[i] = a[i];
        } else {
            l[i] = ceil((long double)l[i + 1] / 2), r[i] = r[i + 1];
            l[i] += a[i], r[i] += a[i];
        }
    }

    if (a[0] > 1) {
        cout << -1;
        return 0;
    }

    nodes = !a[0];
    for (int i = 1; i <= n; ++i) {
        // cout << l[i] << ' ' << r[i] << '\n';
        if (nodes * 2 < l[i]) {
            cout << -1;
            return 0;
        }

        nodes = min(nodes * 2, r[i]);
        ans += nodes;
        nodes -= a[i];
    }

    cout << ans;
}

