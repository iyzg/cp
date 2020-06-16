#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll ans;

void f(string n) {
    if (n.size() == s.size()) {
        bool th, fv, sv, less, pos = true;
        th = fv = sv = less = false;
        for (int i = 0; i < (int)n.size(); ++i) {
            if (n[i] == '3') th = true;
            if (n[i] == '5') fv = true;
            if (n[i] == '7') sv = true;

            if (n[i] < s[i]) less = true;
            else if (n[i] > s[i] && !less) {
                pos = false;
                break;
            }
        }

        if (th && fv && sv && pos) {
            // cout << n << '\n';
            ans++;
        }
    } else {
        bool pre = true;
        for (auto& i : n) {
            if (i != '0') pre = false;
        }

        if (pre) {
            n.push_back('0');
            f(n);
            n.pop_back();
        }
        for (char a = '3'; a <= '7'; a += 2) {
            n.push_back(a);
            f(n);
            n.pop_back();
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    f("");
    cout << ans;
}
