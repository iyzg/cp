#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
bitset<10> cutoff;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    
    int n = s.size() - 1;
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        cutoff.reset();
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cutoff[j] = 1;
            }
        }

        ll cur = 0, cpow = 0;
        for (int j = n; j >= 0; --j) {
            cur += (s[j] - '0') * pow(10, cpow);
            cpow++;
            if (cutoff[n - j] || !j) {
                ans += cur;
                cpow = 0;
                cur = 0;
            }
        }
    }
    cout << ans;
}
