#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string a, b;

void solve() {
    cin >> a >> b;
    vector<int> bc(26, 0);

    for (auto c : b) 
        ++bc[c - 'a'];

    int ans = 0;
    for (auto c : a) {
        if (bc[c - 'a']) {
            --bc[c - 'a'];
            ++ans;
        } else break;
    }

    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
