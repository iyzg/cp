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
    vector<int> dists(n * (n - 1) / 2);
    map<int, int> cnt;
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        cin >> dists[i];
        if (cnt.count(dists[i])) ++cnt[dists[i]];
        else cnt[dists[i]] = 1;
    }

    sort(all(dists));
    vector<int> points;
    points.push_back(0), points.push_back(dists[n * (n - 1) / 2 - 1]);

    int index = 0;
    for (int i = 0; i < n - 2; ++i) {
        bool val = false;
        while (!val) {
            val = true;
            for (auto p : points) {
                if (!cnt.count(abs(dists[index] - p)) || cnt[abs(dists[index] - p)] <= 0)
                    val = false;
                if (!val)
                    break;
            }
            if (!val) ++index;
        }

        for (auto p : points) {
            --cnt[abs(dists[index] - p)];
        }

        points.push_back(dists[index]);
        ++index;
    }

    sort(all(points));
    for (auto i : points) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
