#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;

ll n, x, ans;
ll dp[50], len[50];

void sim(int layer) {
    if (!x) return;
    if (layer == 0) {
        x--;
        ans++;
    } else {
        x--;
        if (!x) return;
        if (x >= len[layer - 1]) {
            x -= len[layer - 1];
            ans += dp[layer - 1];

            if (x) {
                x--;
                ans++;
            } else return;
            
            if (!x) return;
            if (x >= len[layer - 1]) {
                x -= len[layer - 1];
                ans += dp[layer - 1];
            } else {
                sim(layer - 1);
                x--;
            }
        } else {
            sim(layer - 1);
            x--;
        }   
    }   
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    dp[0] = 1, len[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 2ll * dp[i - 1] + 1ll;
        len[i] = len[i - 1] * 2 + 3;
    }

    sim(n);
    cout << ans;
}
    

