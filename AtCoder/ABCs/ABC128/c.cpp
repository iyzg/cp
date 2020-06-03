#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10;

int n, m, k, s, p;

vector<int> conn[N];
bitset<N> def, on;
ll ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> s;
			s--;
			conn[s].push_back(i);
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> p; def[i] = (p == 1);
	}
	
	for (int i = 0; i < (1 << n); i++) {
		on.reset();
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (auto& bulb : conn[j]) {
					on[bulb] = !on[bulb];
				}
			}
		}
		bool valid = true;
		for (int j = 0; j < m; j++) {
			if (on[j] != def[j]) valid = false;
		}
		if (valid) {
			// cout << i << "\n";
			ans++;
		}
	}
	cout << ans;
    return 0;
}
