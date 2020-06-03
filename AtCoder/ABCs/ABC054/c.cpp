#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b;

vector<int> graph[8];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	vector<int> perm;
	for (int i = 1; i < n; i++) perm.push_back(i);
	
	int ans = 0;
	do {
		bool val = false;
		for (auto& i : graph[0]) {
			if (i == perm[0]) val = true;
		} 
		
		if (val) {
			for (int i = 0; i < n - 2; i++) {
				bool found = false;
				for (auto& u : graph[perm[i]]) {
					if (u == perm[i + 1]) found = true;
				}
				if (!found) {
					val = false;
					break;
				}
			}
			
		}
		
		if (val) ans++;
	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << ans;
    return 0;
}
