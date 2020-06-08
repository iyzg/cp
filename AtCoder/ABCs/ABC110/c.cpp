#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string s, t;
char tconn[26], sconn[26];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
 
    bool pos = true;
    for (int i = 0; i < 26; i++) {
        tconn[i] = sconn[i] = '-';
    }
    
    for (int i = 0; i < t.size(); i++) {
        if (tconn[t[i] - 'a'] == '-') {
            tconn[t[i] - 'a'] = s[i];
        } else {
            if (s[i] != tconn[t[i] - 'a']) {
                pos = false;
                break;
            }
        }
        if (sconn[s[i] - 'a'] == '-') {
            sconn[s[i] - 'a'] = t[i];
        } else {
            if (t[i] != sconn[s[i] - 'a']) {
                pos = false;
                break;
            }
        }
 
    }
 
    if (pos) cout << "Yes";
    else cout << "No";
    return 0;
}
