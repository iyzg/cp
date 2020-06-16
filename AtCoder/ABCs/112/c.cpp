#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

list<pair<ll, pair<ll, ll>>> centers;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> a(n);
    for (auto& i : a) {
        cin >> i.second.first >> i.second.second >> i.first;
    }
    // Sort points by increasing height to slowly expand view outwards
    sort(a.begin(), a.end(), greater<pair<ll, pair<ll, ll>>>());

    if (n == 1) {
        // If height of point is 0, then it becomes indeterminable
        cout << a[0].second.first << ' ' << a[0].second.second << ' ' << a[0].first;
        return 0;
    }
    
    // Generate all centers
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            pair<ll, pair<ll, ll>> v;
            v.second = {x, y};
            v.first = a[0].first + abs(x - a[0].second.first) + abs(y - a[0].second.second);
            centers.push_back(v);
        }
    }

    for (int i = 1; i < n; i++) {
        auto it = centers.begin();
        while (it != centers.end()) {
            pair<ll, pair<ll, ll>> v = *it;
            if (max(v.first - abs(v.second.first - a[i].second.first) - abs(v.second.second - a[i].second.second), 0ll) != a[i].first) {
                auto nxt = next(it, 1);  
                centers.erase(it);
                it = nxt;
            } else it++;
        }
    }
    auto it = centers.begin();
    pair<ll, pair<ll, ll>> v = *it;
    cout << v.second.first << ' ' << v.second.second << ' ' << v.first;
}



