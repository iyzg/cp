#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int dp[n + 1], placed[n + 1];
    for (int i = 1; i <= n; i++) {
		cin >> dp[i];
		placed[i] = 0;
	}
    
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
		int sum = 0;
		for (int j = 2 * i; j <= n; j += i) sum	+= placed[j];
		sum %= 2;
		if (sum != dp[i]) {
			placed[i] = true;
			ans.push_back(i);
		}
	}
	
	cout << ans.size() << "\n";
	for (auto& i : ans) cout << i << " ";
    return 0;
}
