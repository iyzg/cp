#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
	vector<pair<int, int>> edges;
    if (n % 2) {
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; j++) {
				if (i + j != n) {
					edges.push_back({i, j});
				}
			}
		}
	} else {
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; j++) {
				if (i + j != n + 1) {
					edges.push_back({i, j});
				}
			}
		}
	}
	
	cout << edges.size() << "\n";
	for (auto& i : edges) cout << i.first << " " << i.second << "\n";
    return 0;
}
