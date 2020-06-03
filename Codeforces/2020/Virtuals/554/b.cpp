#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

map<string, int> m;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s]++;
	}
	int ans = 0;
	for (auto& i : m) ans = max(ans, i.second);
	cout << ans;
    return 0;
}
