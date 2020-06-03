#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, y;

bitset<100> used;
int ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<int, pair<char, int>>> a;
    for (int i = 0; i < 2 * n; i++) {
		cin >> x >> y;
		if (i < n) a.push_back({x, {'r', y}});
		else a.push_back({x, {'b', y}});
	}
	sort(a.begin(), a.end());
	
	multiset<int, greater<int>> cur;
	for (auto& i : a) {
		if (i.second.first == 'r') cur.insert(i.second.second);
		else {
			int by = i.second.second;
			for (auto it = cur.begin(); it != cur.end(); it++) {
				if (by > *it) {
					ans++;
					cur.erase(it);
					break;
				}
			}
		}
	}

    cout << ans;
    return 0;
}
