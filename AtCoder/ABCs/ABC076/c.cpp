#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    
    bool fixed = false;
    for (int i = s.size() - t.size(); i >= 0; --i) {
		if (s[i] == t[0] || s[i] == '?') {
			bool valid = true;
			for (int j = 0; j < t.size(); j++) {
				if (s[i + j] != '?' && s[i + j] != t[j]) valid = false;
			}
			
			if (valid) {
				fixed = true;
				for (int j = 0; j < t.size(); j++) {
					s[i + j] = t[j];
				}
				for (int j = 0; j < s.size(); j++) {
					if (s[j] == '?') s[j] = 'a';
				}
				break;
			}
		}
	}
    
    fixed ? cout << s : cout << "UNRESTORABLE";
    return 0;
}
