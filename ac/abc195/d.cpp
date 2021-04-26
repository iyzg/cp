#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, q;
vector<pii> bags;
int boxes[50];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        int w, v;
        cin >> w >> v;
        bags.push_back({v, w});
    }
    
    sort(bags.rbegin(), bags.rend());

    for (int i = 0; i < m; ++i) {
        cin >> boxes[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        vector<int> avail_boxes;
        vector<bool> avail(50, true);

        for (int j = 0; j < m; ++j) {
            if (j < l || j > r) avail_boxes.push_back(boxes[j]);
        }
        sort(all(avail_boxes));

        int ans = 0;
        for (int bag = 0; bag < n; ++bag) {
            for (int abox = 0; abox < sz(avail_boxes); ++abox) {
                if (bags[bag].second <= avail_boxes[abox] && avail[abox]) {
                    avail[abox] = false;
                    ans += bags[bag].first;
                    break;
                }
            }
        }



        cout << ans << '\n';
    }
}
