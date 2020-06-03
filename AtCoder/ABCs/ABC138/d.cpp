#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

int n, q, a, b;
vector<int> conn[N];
int val[N];

void dfs(int v, int p) {
	for (auto& u : conn[v]) {
		if (u != p) {
			val[u] += val[v];
			dfs(u, v);
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		a--; b--;
		conn[a].push_back(b);
		conn[b].push_back(a);
	}	
	
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		a--;
		val[a] += b;
	}
	
	dfs(0, -1);
	for (int i = 0; i < n; ++i) cout << val[i] << " ";
	
    return 0;
}
