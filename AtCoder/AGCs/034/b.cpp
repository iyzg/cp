#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    ll ans = 0, ac = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] == 'A') ac++;
        else if (s[i] == 'B' && s[i + 1] == 'C') {
            ans += ac;
            i++;
        } else ac = 0;
    }
    cout << ans;
}   
    
