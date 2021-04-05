#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 2 * 1e6;

int n, m;
int a[MX], cnt[MX];

set<int> pos;
int uniq;
int ans = MX, curr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, m) {
        ++cnt[a[i]];
        if (cnt[a[i]] == 1) ++uniq;
    }

    rep(i, 0, m + 1) {
        if (!cnt[i]) {
            ans = i;
            curr = i;
            break;
        }
    }

    // cout << ans << '\n';
    rep(i, m, n) {
        --cnt[a[i - m]];
        ++cnt[a[i]];

        if (cnt[a[i]] == 1) ++niq;
        if (!cnt[a[i - m]]) {
            if (a[i - m] < curr) cur = a[i - m];
            --uniq;
        }



        if (uniq == m) ans = min(ans, m); 
        else 


        if (!cnt[a[i - m]]) pos.insert(a[i - m]);

        ++cnt[a[i]];
        pos.erase(a[i]);
        ans = min(ans, *pos.begin());
    }

    cout << ans;
}
