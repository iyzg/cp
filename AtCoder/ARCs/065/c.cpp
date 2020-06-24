#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    reverse(s.begin(), s.end());
    int l = 0;
    while (l < s.size()) {
		if (s.size() - l < 5) {
			cout << "NO";
			return 0;
		}		
		
		if (s.substr(l, 5) == "maerd") {
			l += 5;
		} else if (s.substr(l, 5) == "esare") {
			l += 5;
		} else if (s.size() - l >= 6 && s.substr(l, 6) == "resare") {
			l += 6;
		} else if (s.size() - l >= 7 && s.substr(l, 7) == "remaerd") {
			l += 7;
		} else {
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
    return 0;
}
