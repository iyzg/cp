#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MX = 2 * 1e5 + 5;

ll n, c, ans;
ll price[MX];

// 0 means not currently using service
bool on[MX];

vector<pair<ll, ll>> days;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        price[i] = c;
        days.push_back({a, i});
        days.push_back({b + 1, i});
    }

    sort(all(days));
    ll day = -1, cost = 0;

    for (int i = 0; i < sz(days); ++i) {
        ll curD = days[i].first, sv = days[i].second;
        if (curD != day) {
            // cout << curD << ' ' << day << ' ' << cost << ' ' << c << '\n';
            ans += (curD - day) * min(cost, c);
        }

        on[sv] = !on[sv];
        if (!on[sv]) cost -= price[sv];
        else cost += price[sv];

        day = curD;
    }
    
    cout << ans;
}
