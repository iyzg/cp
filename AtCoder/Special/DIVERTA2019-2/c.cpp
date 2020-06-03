#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int ans;
vector<pair<int, int>> seq;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    if (a[n - 1] <= 0) {
		ans = a[n - 1];
		for (int i = 0; i < n - 1; i++) {
			seq.push_back({ans, a[i]});
			ans -= a[i];
		}
	} else {
		ans = a[0];
		for (int i = 1; i < n - 1; i++) {
			if (a[i] >= 0) {
				seq.push_back({ans, a[i]});
				ans -= a[i];
			}
		}
		seq.push_back({a[n - 1], ans});
		ans = a[n - 1] - ans;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] < 0) {
				seq.push_back({ans, a[i]});
				ans -= a[i];
			}
		}
	}
	
	cout << ans << "\n";
	for (auto& i : seq) cout << i.first << " " << i.second << "\n";
    return 0;
}
