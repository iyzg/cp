#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int n, k, x;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> neg, pos;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) k--; 
        else if (x < 0) neg.push_back(x);
        else pos.push_back(x);
    }
    
    if (!k) {
        cout << 0;
        return 0;
    }

    sort(neg.begin(), neg.end(), greater<ll>());

    ll ans = INF;
    int nt = min(k, (int)neg.size()), pt = k - nt;
    while (nt >= 0 && pt <= (int)pos.size()) {
        ll dist = 0;
        if (nt > 0) dist = abs(neg[nt - 1]);
        if (pt > 0) {
            if (pos[pt - 1] < dist) dist += pos[pt - 1] * 2;
            else {
                dist *= 2;
                dist += pos[pt - 1];
            }
        }
        
        ans = min(ans, dist);
        nt--;
        pt++;
    }
    cout << ans;
}
