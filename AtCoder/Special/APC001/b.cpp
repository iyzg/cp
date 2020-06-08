#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll b;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
    }
    sort(diff.begin(), diff.end(), greater<ll>());

    ll overflow = 0;
    for (auto& i : diff) {
        if (i >= 0) overflow += i / 2;
        else {
            i = -i;
            if (overflow < i) {
                cout << "No";
                return 0;
            }
            overflow -= i;
        }   
    }

    cout << "Yes";
}
