#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000;

ll n, m;
ll a[N][3];
ll ans = -1e18;

void f(string s) {
    if (s.size() == 3) {
        ll mul[3];
        for (int i = 0; i < 3; ++i) {
            if (s[i] == '+') mul[i] = 1;
            else mul[i] = -1;
        }
            
        ll score = 0;
        vector<ll> best;
        for (int i = 0; i < n; ++i) {
            ll tmp = 0;
            for (int j = 0; j < 3; ++j) {
                tmp += a[i][j] * mul[j];
            }
            best.push_back(tmp);
        }
        sort(best.begin(), best.end(), greater<ll>());
        for (int i = 0; i < m; ++i) score += best[i];
        ans = max(ans, score);
        return;
    }

    f(s + "+");
    f(s + "-");
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    f("");
    cout << ans;
}
