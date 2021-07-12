#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt = 1;

void solve() {
    int n; cin >> n;
    vector<int> cars(n), people(4 * n);
    for (auto& i : cars) cin >> i;
    for (auto& i : people) cin >> i;

    int ans = -1;
    sort(all(cars));
    sort(all(people), greater<int>());
    for (int i = 0; i < n; ++i) {
        ans = max(ans, cars[i] + people[4 * i]);
    }

    cout << "Trip #" << cnt << ": " << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (cnt <= t) {
        solve();
        ++cnt;
    }
}
