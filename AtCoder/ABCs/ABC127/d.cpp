#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
	
	vector<pair<ll, ll>> pairs(m);
	for (auto& i : pairs) cin >> i.second >> i.first;
	sort(pairs.begin(), pairs.end());
	
	ll sum = 0, added = 0;
	int ai = n - 1, pi = m - 1;
	while (added < n) {
		if (pi >= 0 && ai >= 0) {
			if (pairs[pi].first >= a[ai]) {
				ll chosen = min(n - added, pairs[pi].second);
				sum += chosen * pairs[pi].first;
				added += chosen;
				pi--;				
			} else {
				sum += a[ai];
				ai--;
				added++;
			}
		} else if (pi >= 0) {
			int chosen = min(n - added, pairs[pi].second);
			sum += chosen * pairs[pi].first;
			added += chosen;
			pi--;
		} else {
			sum += a[ai];
			ai--;
			added++;
		}
	}
	cout << sum;
    return 0;
}
