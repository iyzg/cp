#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>> points;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        points.push_back({a, 0});
        points.push_back({b, 1});
    }

    sort(points.begin(), points.end());

    ll lb = -1, rb = -1;
    ll ahead = 0, after = 0;
    // Fine for odd and bottom half for even
    ll need = (ll)ceil((long double)n / 2) - 1;
    for (auto point : points) {
        ll loc = point.first, type = point.second;
        if (ahead - type >= need && ahead - after <= need) {
            if (lb == -1) {
                lb = loc;
                rb = loc;
            } else {
                rb = loc;
            }
        } else if (lb != -1) break;

        if (type) --after;
        else {
            ++ahead;
            ++after;
        }
    }

    if (!(n % 2)) {
        ll ulb = -1, urb = -1;
        ll ahead = 0, after = 0;
        // Fine for odd and bottom half for even
        ll need = n / 2;
        for (auto point : points) {
            ll loc = point.first, type = point.second;
            if (ahead - type >= need && ahead - after <= need) {
                if (ulb == -1) {
                    ulb = loc;
                    urb = loc;
                } else {
                    urb = loc;
                }
            } else if (ulb != -1) break;

            if (type) --after;
            else {
                ++ahead;
                ++after;
            }
        }
        // cout << lb << ' ' << rb << ' ' << ulb << ' ' << urb << '\n';
        ld tlb = (ulb + lb) / (long double)2, trb = (urb + rb) / (long double)2;
        // cout << tlb << ' ' << trb << '\n';
        cout << (ll)((trb - tlb) * 2 + 1);
    } else {
        // Range is inclusive
        cout << rb - lb + 1;
    }
}
