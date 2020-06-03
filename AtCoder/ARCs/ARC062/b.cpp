#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int ans, rock, paper;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    
    for (auto c : s) {
		if (c == 'g') {
			if (paper < rock) {
				ans++;
				paper++;
			} else {
				rock++;
			}
		} else {
			if (paper < rock) {
				paper++;
			} else {
				rock++;
				ans--;
			}
		}
	}
	
	cout << ans;
    return 0;
}
