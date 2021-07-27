#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string line;
multiset<int> lens;
int total, strSz;

bool bf(int rows) {
    multiset<int> tmp = lens;
    int target = total / rows;
    if (*lens.begin() > target) return false;

    while (!tmp.empty()) {
        int cur = *prev(tmp.end());
        tmp.erase(prev(tmp.end()));

        while (cur < target) {
            auto it = tmp.lower_bound(target - cur - 1);
            if (it == tmp.end() || *it + cur + 1 != target) {
                it = tmp.upper_bound(target - cur - (*tmp.begin() + 1) - 1);
                if (it == tmp.begin()) return false;
                it = prev(it);
                cur += *it + 1;
                tmp.erase(it);
            } else {
                cur += *it + 1;
                tmp.erase(it);
            }
        }

        if (cur != target) return false;
    }

    return true;
}

void solve() {
    getline(cin, line);
    lens.clear();

    strSz = 0;

    for (auto c : line) {
        if (c == ' ') {
            lens.insert(strSz);
            strSz = 0;
        } else ++strSz;
    }

    if (strSz) {
        lens.insert(strSz);
    }

    bool ans = false;
    for (int groups = 2; groups <= sz(lens); ++groups) {
        if (ans) break;

        total = sz(line) - (groups - 1);
        if (!(total % groups)) {
            // cout << "Trying: " << groups << ' ' << total << '\n';
            ans = bf(groups);
        }
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    getline(cin, line);
    while (t--)
        solve();
}
