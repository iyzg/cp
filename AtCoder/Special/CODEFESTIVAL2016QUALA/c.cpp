#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll k;
    
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s >> k;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') continue;
        int cost = 26 - (s[i] - 'a');
        // cout << i << " " << cost << " " << k << '\n';
        if (cost <= k) {
            s[i] = 'a';
            k -= cost;
        }
    }
    
    k %= 26;
    s[n - 1] = s[n - 1] + k;
    cout << s;
}   

