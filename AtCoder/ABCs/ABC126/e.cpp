#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;

int n, m, x, y, z;

vector<int> graph[N];
bitset<N> used;

void dfs(int v) {
	used[v] = 1;
	for (auto& u : graph[v]) {
		if (!used[u]) dfs(u);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	used.reset();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
    return 0;
}
