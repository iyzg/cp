#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;

int n, m;
vector<int> conn[N];
int used[N];
bool pos = true;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++) {
		int v = a[i].second, req = a[i].first;
		if (used[v] + 1 == req) {
			for (auto& u : conn[v]) {
				if (used[u] == used[v]) used[u]++;
			}
		} else {
			pos = false;
			break;
		}
	}
	
	if (pos) {
		for (int i = 0; i < n; i++) {
			cout << a[i].second + 1 << " ";
		}
	} else cout << -1;
    return 0;
}
