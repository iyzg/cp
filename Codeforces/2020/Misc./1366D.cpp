#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            b[i] = -1;
            c[i] = -1;
        } else {
            if (a[i] / (1 << __builtin_ctz(a[i])) == 1) {
                b[i] = -1;
                c[i] = -1;
            } else {
                b[i] = 2;
                c[i] = a[i] / (1 << __builtin_ctz(a[i]));
            }
        }
    }

    for (auto& i : b) cout << i << ' ';
    cout << '\n';
    for (auto& i : c) cout << i << ' ';
}

