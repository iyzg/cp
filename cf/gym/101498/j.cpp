#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string line;
vector<int> lens;
int total, strSz;

void solve() {
    getline(cin, line);
    lens.clear();

    strSz = 0;

    for (auto c : line) {
        if (c == ' ') {
            lens.push_back(strSz);
            strSz = 0;
        } else ++strSz;
    }

    if (strSz) {
        lens.push_back(strSz);
    }

    bool ans = false;
    for (int groups = 2; groups <= sz(lens); ++groups) {
        total = sz(line) - (groups - 1);
        if (total % groups) continue;
        int target = total / groups;

        int tmp = 0;
        bool val = true;
        for (int i = 0; i < sz(lens); ++i) {
            if (!tmp) tmp += lens[i];
            else tmp += lens[i] + 1;

            if (tmp >= target) {
                val = (val & (tmp == target));
                tmp = 0;
            }
        }

        ans = ans | val;
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
