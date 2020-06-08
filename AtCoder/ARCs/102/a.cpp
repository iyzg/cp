#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double EPS = 1e-9;

ll n, k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    if (k % 2) {
        cout << (ll)(pow((long double)(n / k), 3) + EPS);
    } else {
        ll ans = (ll)(pow((long double)(n / k), 3) + EPS);
        ll hm = n / k;
        if (n % k >= k / 2) hm++;
        ans += (ll)(pow((long double)hm, 3) + EPS); 
        cout << ans;
    }
}
