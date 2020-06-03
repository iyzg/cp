#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int n, m, p, y;
int before[N];

map<pair<int, int>, int> order;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
		cin >> p >> y;
		a[i] = {p, y};
		order[{p, y}] = i;
	}
	sort(a.begin(), a.end());
	
	vector<string> ans(m);
	
	for (int i = 0; i < m; i++) {
		string pre, id;
		pre = to_string(a[i].first);
		before[a[i].first]++;
		id = to_string(before[a[i].first]);
		while (pre.size() < 6) pre = '0' + pre;
		while (id.size() < 6) id = '0' + id;
		string fin = pre + id;
		ans[order[{a[i].first, a[i].second}]] = fin;
	}
	
	for (auto s : ans) cout << s << "\n";
    return 0;
}
