#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;

int n, m, q, l, r;

int dp[N][N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
		cin >> l >> r;
		dp[l][r]++;
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	while (q--) {
		cin >> l >> r;
		cout << dp[r][r] - dp[l - 1][r] << "\n";
	}
	
    return 0;
}
