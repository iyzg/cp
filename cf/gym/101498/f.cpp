#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, k;

void solve() {
    cin >> n >> k;

    set<pair<int, int>> cache;
    map<int, queue<int>> next;
    int order[n];

    for (int i = 0; i < n; ++i) {
        cin >> order[i];
        next[order[i]].push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int no = n - next[order[i]].front();

        if (cache.find({no, order[i]}) != cache.end()) {
            cache.erase({no, order[i]});
            next[order[i]].pop();
            sz(next[order[i]]) == 0 ? no = -1 : no = n - next[order[i]].front();
            cache.insert({no, order[i]});
        } else {
            ++ans;
            if (sz(cache) == k) {
                cache.erase(cache.begin());
            }

            next[order[i]].pop();
            sz(next[order[i]]) == 0 ? no = -1 : no = n - next[order[i]].front();
            cache.insert({no, order[i]});
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
