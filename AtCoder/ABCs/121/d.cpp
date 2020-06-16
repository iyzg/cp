#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b;
ll ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i < 45; i++) {
        ll start;
        if (a % (1ll << i) == 0) start = a;
        else {
            start = a + ((1ll << i) - (a % (1ll << i)));
        }
        ll cnt = 0;
        // 5, 7, cur pow is 2^2 aka 4
        // if (start % (1ll << i) == 0) {
            // cnt = start - a - max(0ll, start - 1 - b);
            // start += (1ll << i);
        // }
        if ((start / (1ll << i)) % 2 == 0) {
            cnt += min(start - 1, b) - a + 1;
            start += (1ll << i);
        }

        if (start > b) {
            // cout << i << ' ' << cnt << ' ' << start << '\n';
            if (cnt % 2) ans += (1ll << i);
            continue;
        }



        // cout << i << ' ' << cnt << ' ' << start << '\n';
        ll mul = (b - start + 1) / (1ll << i);
        cnt += ceil((long double)mul / 2) * (1ll << i);
        start += (1ll << i) * mul;
        if (mul % 2 == 1) start++;
        if (mul % 2 == 0 && start <= b) cnt += b - start + 1;
        // cout << i << ' ' << mul << ' ' << cnt << ' ' << start << '\n';
        if (cnt % 2) ans += (1ll << i);
    }
    cout << ans;
}

