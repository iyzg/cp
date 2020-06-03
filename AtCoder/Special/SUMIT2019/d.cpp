#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30000;

int n, uni[N];
char s[N];

ll ans;
set<char> seen;
bool done[10][10];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n - 1; i >= 0; --i) {
		seen.insert(s[i]);
		uni[i] = seen.size();
	}
	
	
    for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (!done[s[i] - '0'][s[j] - '0']) {
				done[s[i] - '0'][s[j] - '0'] = true;
				ans += uni[j + 1];
			}
		}
	}
    
    cout << ans;
    return 0;
}
