#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;

    for (int team = 1; team <= t; ++team) {
        int g, p; cin >> g >> p;

        cout << "Team #" << team << '\n';
        cout << "Games: " << g << '\n';
        cout << "Points: " << p << '\n';
        cout << "Possible records: " << '\n';

        for (int gw = g; gw >= 0; --gw) {
            if (3 * gw > p || 3 * gw + (g - gw) < p) continue;
            int ties = p - 3 * gw;
            int losses = g - gw - ties;
            cout << gw << '-'  << ties << '-' << losses << '\n';
        }

        cout << '\n';
    }
}
