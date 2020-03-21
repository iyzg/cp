#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, ans = -1;
char fMove;;
// hoof, paper, scissor and how many points they get
int dp[3][100000];

int main() {
	setIO("hps");
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> fMove;
		if (fMove == 'P') {
			dp[2][i]++;;
		} else if (fMove == 'S') {
			dp[0][i]++;
		} else {
			dp[1][i]++;			
		}
	}
	for(int i = 1; i < N; i++) {
		dp[0][i] += dp[0][i - 1];
		dp[1][i] += dp[1][i - 1];
		dp[2][i] += dp[2][i - 1];
	}
	ans = max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1]));
	for(int i = 0; i < N; i++) {
		ans = max(ans, dp[0][i] + dp[1][N - 1] - dp[1][i]);
		ans = max(ans, dp[0][i] + dp[2][N - 1] - dp[2][i]);
		ans = max(ans, dp[1][i] + dp[0][N - 1] - dp[0][i]);
		ans = max(ans, dp[1][i] + dp[2][N - 1] - dp[2][i]);
		ans = max(ans, dp[2][i] + dp[0][N - 1] - dp[0][i]);
		ans = max(ans, dp[2][i] + dp[1][N - 1] - dp[1][i]);
	}
	cout << ans << "\n";
    return 0;
}
