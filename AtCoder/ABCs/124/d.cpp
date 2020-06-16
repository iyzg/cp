#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
string s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> s;
    vector<pair<int, int>> a;
    int len = 0;
    for (int i = 0; i < n; i++) {
        len++;
        if ((i < n - 1 && s[i] != s[i + 1]) || i == n - 1) {
            a.push_back({len, s[i] - '0'});
            len = 0;
        }
    }

    int ops = !a[0].second, ans = 0;
    for (int l = 0, r = 0, cur = a[0].first; l < (int)a.size(); l++) {
        r = max(l, r);
        if (l > 0) {
            cur -= a[l - 1].first;
            ops -= (!a[l - 1].second);
        }
        
        while (r < (int)a.size() - 1 && ops + !a[r + 1].second <= k) {
            r++;
            cur += a[r].first;
            ops += (!a[r].second);
        }

        ans = max(ans, cur);
    }

    cout << ans;
}
