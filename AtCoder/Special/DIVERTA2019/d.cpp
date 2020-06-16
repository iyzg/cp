#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (ll mod = 1; mod * mod <= n; mod++) {
        if ((n % mod) || (n == 1 && mod == 1) || n % (n / mod - 1) != mod) continue;
        ans += n / mod - 1;
    }
    
    cout << ans;
}

