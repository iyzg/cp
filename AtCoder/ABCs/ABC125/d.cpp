#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 100005;

int N;

// dp[0] is no flip, [1] is flip
ll dp[MX][2];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<ll> a(N);
    for (auto& i : a) cin >> i;
    
    dp[0][0] = a[0], dp[0][1] = -a[0];
    for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + -a[i]);
		dp[i][1] = max(dp[i - 1][0] + -a[i], dp[i - 1][1] + a[i]);
		// cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
    
    cout << dp[N - 1][0];
    return 0;
}
