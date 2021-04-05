#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;

ll cnt[26];

ll ans = 0;


int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    ll n = sz(s);
    cnt[s[n - 1] - 'a']++, cnt[s[n - 2] - 'a']++;
    for (int i = n - 3; i >= 0; --i) {
        // If end of group
        ll li = s[i] - 'a';
        if (s[i] == s[i + 1] && s[i] != s[i + 2]) {
            ans += (n - i - 1) - cnt[li];
            for (int i = 0; i < 26; ++i) cnt[i] = 0;
            cnt[li] = n - i;
        } else {
            cnt[li]++;
        }
    }
    
    cout << ans;
}
