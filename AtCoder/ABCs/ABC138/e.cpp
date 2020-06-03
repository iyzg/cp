#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, cur;
string s, t;
set<int> nxt[26];
ll ans = 0;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    n = s.size();
    for (int i = 0; i < n; i++) {
		nxt[s[i] - 'a'].insert(i + 1);
	}
    
    for (auto& c : t) {
		int index = c - 'a';
		if (!nxt[index].size()) {
			cout << -1;
			return 0;
		} 
		
		auto it = nxt[index].upper_bound(cur);
		if (it == nxt[index].end()) {
			it = nxt[index].begin();
			ans += n - cur;
			ans += *it;
			cur = *it;
		} else {
			ans += *it - cur;
			cur = *it;
		}
	}
	
	cout << ans;
    return 0;
}
