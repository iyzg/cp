#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int tc = 1;
map<char, int> m;

void solve() {
    string s; cin >> s;
    ll pos = 0;

    ll tpos = 1;
    for (int i = 0; i < sz(s); ++i) {
        // cout << i << ' ' << s[i] << ' ' << (m.find(s[i]) == m.end()) << '\n';
        if (i % 2 == 0 && (m.find(s[i]) == m.end() && s[i] != '?')) tpos = 0;
        if (i % 2 == 0 && s[i] == '?') tpos *= 6;

        if (i % 2 == 1 && m.find(s[i]) != m.end()) tpos = 0;
        if (i % 2 == 1 && s[i] == '?') tpos *= 20;
    }
    pos += tpos;
    
    tpos = 1;
    for (int i = 0; i < sz(s); ++i) {
        if (i % 2 == 1 && (m.find(s[i]) == m.end() && s[i] != '?')) tpos = 0;
        if (i % 2 == 1 && s[i] == '?') tpos *= 6;

        if (i % 2 == 0 && m.find(s[i]) != m.end()) tpos = 0;
        if (i % 2 == 0 && s[i] == '?') tpos *= 20;
    }
    pos += tpos;

    cout << "String #" << tc << ": " << pos << "\n\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = m['y'] = 1;
    for (; tc <= t; ++tc)
        solve();
}
