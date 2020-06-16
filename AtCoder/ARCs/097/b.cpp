#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;

int n, m;

int parent[N], sz[N];
set<int> con[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    con[v].insert(v);
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        con[a].insert(con[b].begin(), con[b].end());
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
		cin >> a[i];
		make_set(i);
	}
    
    vector<pair<int, int>> pairs(m);
    for (auto& i : pairs) {
		cin >> i.first >> i.second;
		i.first--; i.second--;
		union_sets(i.first, i.second);
	}
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
		int g = find_set(i);
		if (con[g].find(a[i] - 1) != con[g].end()) {
			ans++;
		}
	}
    
    cout << ans;
    return 0;
}
