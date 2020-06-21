#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, q;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> q;
    set<ll> shrines, temples;
    for (int i = 0; i < a; ++i) {
        ll s; cin >> s;
        shrines.insert(s);
    }

    for (int i = 0; i < a; ++i) {
        ll t; cin >> t;
        temples.insert(t);
    }

    for (int i = 0; i < q; ++i) {
        ll x; cin >> x;
        // Find next temple and shrine on both sides
