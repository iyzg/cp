#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t; 
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        for (int j = s.size(); j >= 0; --j) {
            if (s[j] == 'p') {
                s[j] = 'q';
            } else if (s[j] == 'q')  {
                s[j] = 'p';
            }
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}
