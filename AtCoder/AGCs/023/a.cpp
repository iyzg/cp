#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
map<ll, ll> m;
ll ans, pre;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    m.insert({0, 1});

    for (int i = 0; i < n; i++) {
        int A; cin >> A;
        pre += A;
        ans += m[pre];
        m[pre]++;
    }
    cout << ans;
}
