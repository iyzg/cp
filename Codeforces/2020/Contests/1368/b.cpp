#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll k;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> k;
    
    ll lc[10];

    for (int i = 0; i < 10; i++)
        lc[i] = 1;

    int index = 0;
    ll seq = 1;
    while (seq < k) {
        seq /= lc[index];
        lc[index]++;
        seq *= lc[index];
        index++;
        index %= 10;
    }

    string s = "codeforces";
    string ans = "";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < lc[i]; j++) {
            ans += s[i];
        }
    }

    cout << ans;

}
