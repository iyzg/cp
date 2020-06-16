#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll dp[10][10];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        dp[s[0] - '0'][s[s.size() - 1] - '0']++;
    }
    
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            if (i != j) ans += 2 * (dp[i][j] * dp[j][i]);
            else ans += (dp[i][j] * dp[j][i]);
        }
    }
    cout << ans;
}   

