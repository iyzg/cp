#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    multiset<ll> groups;
    
    for (int i = n - 1; i >= 0; --i) {
        auto ub = groups.upper_bound(a[i]);
        if (ub != groups.end()) 
            groups.erase(ub);
        groups.insert(a[i]);
    }

    cout << groups.size();
}

