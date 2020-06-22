#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n;
vector<pair<ll, ll>> a;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());

}
