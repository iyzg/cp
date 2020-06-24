#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int D = 10;

ll d, g;
ll p[D], c[D];
ll ans = 100000;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> d >> g;
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }

    vector<int> perm(d);
    for (int i = 0; i < d; ++i) perm[i] = i;
    do {
        ll score = 0, taken = 0;
        for (auto diff : perm) {
            ll tot = min(p[diff], (g - score) / (100 * (diff + 1)));
            taken += tot;
            // cout << diff << ' ' << score << ' ' << tot << '\n';
            score += tot * 100 * (diff + 1);
            if (tot == p[diff]) score += c[diff];
            score = min(score, g);
        }
        ans = min(ans, taken);
        // cout << taken << '\n';
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans;
}
