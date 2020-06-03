#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 200005;

int N;
ll a[MX], b[MX], c[MX], zeros[MX], ones[MX], cost[MX];
bool wrong[MX];
vector<int> graph[MX];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i] >> c[i];
		wrong[i] = (b[i] == c[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	// Reverse bfs
	queue<int> q;
	stack<int> rq;
	vector<bool> vis(N, false);
	vector<int> par(N, -1);
	q.push(0);
	rq.push(0);
	vis[0] = true;
	while(!q.empty()) {
		int v = q.top();
		q.pop();
		for (auto& u : graph[v]) {
			if (!vis[u]) {
				rq.push(u);
				q.push(u);
				par[u] = v;
				vis[u] = true;
			}
		}
	}
	
	while (!rq.empty()) {
		int v = q.top();
		for (auto& u : graph[v]) {
			if (par[u] == v) {
				zeros[v] += zeros[u];
				ones[v] += ones[u];
				if (wrong[u]) wrong[v] = true;
			}
		}
		
	}
    return 0;
}
