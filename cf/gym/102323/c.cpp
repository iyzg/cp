#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int d, j;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int day = 1; day <= t; ++day) {
        cin >> d >> j >> s;

        int ans = 0, index = 0;
        while (index != sz(s) - 1) {
            bool jumped = false;
            for (int i = j + 1; i > 0; --i) {
                if (index + i < sz(s) && s[index + i] != 'X') {
                    jumped = true;
                    index = index + i;
                    ++ans;
                    break;
                }
            }

            if (!jumped) {
                ans = 0;
                break;
            }
        }

        cout << "Day #" << day << '\n';
        cout << d << ' ' << j << '\n';
        cout << s << '\n';
        cout << ans << '\n';
        cout << '\n';
    }
}
