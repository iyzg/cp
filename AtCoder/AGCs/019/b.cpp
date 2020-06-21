#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
map<char, int> m;

ll ans = 1;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;

    m[s[0]]++;
    for (int i = 1; i < (int)s.size(); ++i) {
        // cout << i << ' ' << m[s[i]] << '\n';
        ans += i - m[s[i]];
        m[s[i]]++;
    }

    cout << ans;
}
