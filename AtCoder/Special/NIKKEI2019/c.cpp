#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n;
bitset<N> eaten;

ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    eaten.reset();
    cin >> n;
    // A for takashi ordering, b for aoki
    vector<pair<int, pair<int, int>>> a, b;
    for (int i = 0 ; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x + y, {x, i}});
        b.push_back({x + y, {y, i}});
    }
    sort(a.begin(), a.end(), greater<pair<int, pair<int, int>>>());
    sort(b.begin(), b.end(), greater<pair<int, pair<int, int>>>());
    int ai = 0, bi = 0;
    for (int i = 0; i < n; i++) {
        if (!(i % 2)) {
            while (eaten[a[ai].second.second]) ai++;
            eaten[a[ai].second.second] = true;
            ans += a[ai].second.first;
        } else {
            while (eaten[b[bi].second.second]) bi++;
            eaten[b[bi].second.second] = true;
            ans -= b[bi].second.first;
        }
    }
    cout << ans;
}
