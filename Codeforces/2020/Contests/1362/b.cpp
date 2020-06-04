#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
bitset<1300> used;

void solve() {
	cin >> n;
	set<int> avail; 
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
		avail.insert(i);
	}
	
	sort(a.begin(), a.end());
	
	if (n == 1) {
		cout << -1 << "\n";
		return;
	}
	
	int ans = 1025;
	
	for (int i = 1; i < n; i++) {
		used.reset();
		int req = a[0] ^ a[i];
		bool pos = true;
		used[a[0]] = 1; used[a[i]] = 1;
		
		for (int j = 1; j < n; j++) {
			if (used[a[j]]) continue;
			int res = a[j] ^ req;
			// cout << i << " " << j << " " << res << "\n";
			if (avail.find(res) == avail.end() || used[res]) {
				pos = false;
				break;
			} else {
				used[a[j]] = 1;
				used[res] = 1;
			}
		}
		
		if (pos && req > 0) {
			// cout << "req: " << req << "\ne";
			ans = min(req, ans);
		}
	}
	
	if (ans == 1025) {
		cout << -1 << "\n";
	} else cout << ans << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
		solve();
	}
    return 0;
}
