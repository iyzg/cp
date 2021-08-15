#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
int cnt[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (auto c : s)
        cnt[c - 'a']++;

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 == 1) break;
        if (i == 25) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 == 0 && cnt[i] > 0) break;
        if (i == 25) {
            cout << 1;
            return 0;
        }
    }

    cout << 2;
}
