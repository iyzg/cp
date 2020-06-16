#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 5;

int n, k;
ll ans = INF;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        x[i] = a[i].first, y[i] = a[i].second;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);

    for (int xi = 0; xi < n; xi++) {
        for (int xj = xi + 1; xj < n; xj++) {
            for (int yi = 0; yi < n; yi++) {
                for (int yj = 0; yj < n; yj++) {
                    int num = 0;
                    ll lx = x[xi], rx = x[xj];
                    ll by = y[yi], uy = y[yj];

                    for (int i = 0; i < n; i++) {
                        if (a[i].first >= lx && a[i].first <= rx && a[i].second >= by && a[i].second <= uy) num++;
                    }

                    if (num >= k) {
                        ans = min(ans, (rx - lx) * (uy - by));
                    }
                }
            }
        }
    }
    
    cout << ans;
}

