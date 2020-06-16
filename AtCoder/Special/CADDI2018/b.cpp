#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    bool odd = false;
    ll sum = 0;
    for (auto& i : a) {
        cin >> i;
        if (i % 2) odd = true;
    }
    odd ? cout << "first" : cout << "second";
}

    

