#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

void solve() {
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        string ch; int f;
        cin >> ch >> f;
        if (freq.count(f)) ++freq[f];
        else freq[f] = 1;
    }

    int ans = -1, num = -1;
    for (auto i : freq) {
        if (i.second > num) {
            ans = i.first;
            num = i.second;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
