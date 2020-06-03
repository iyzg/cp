#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;

struct Comp {
	bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) {
		if (a.first != b.first) {
			return a.first < b.first;
		}
		return a.second > b.second;
	}		
};

int n;

// 0 = don't take, 1 = take
int dp[N][2];


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
		ll x, l;
		cin >> x >> l;
		a[i].first = x + l;
		a[i].second = max(0ll, x - l);
	}
    sort(a.begin(), a.end(), Comp());
    
	dp[0][0] = 0;
	dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
		// cout << a[i].first << " " << a[i].second << "\n";
		auto it = lower_bound(a.begin(), a.end(), make_pair(a[i].second, -1ll), Comp());
		if (it == a.begin()) {
			dp[i][1] = 1;
			// cout << "oof";
		} else {
			--it;
			int index = distance(a.begin(), it);
			// cout << "index: " << index << "\n";
			dp[i][1] = max(dp[index][1], dp[index][0]) + 1;
		}
		dp[i][0] = max(dp[i - 1][1], max(dp[i - 1][0], 0));
		// cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
    
    cout << max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}
