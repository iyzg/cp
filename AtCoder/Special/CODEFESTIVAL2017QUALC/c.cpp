#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    string ns;
    for (auto& i : s) {
        if (i != 'x') ns += i;
    }
        
    int n = ns.size();
    
    if (n == 0) {
        cout << 0;
        return 0;
    }

    // Check if string without x's is a palindrome
    bool palin = false;
    if (n % 2) {
        string fir = ns.substr(0, n / 2), sec = ns.substr(n / 2 + 1, n / 2);
        reverse(sec.begin(), sec.end());
        if (fir == sec) palin = true;
    } else {
        string fir = ns.substr(0, n / 2), sec = ns.substr(n / 2, n / 2);
        reverse(sec.begin(), sec.end());
        if (fir == sec) palin = true;
    }

    if (!palin) {
        cout << -1;
        return 0;
    } 
    
    int l = 0, r = 0, nsi = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ns[nsi]) {
            if (n % 2) {
                if (nsi == n / 2) {
                    l = i; r = i;
                    break;
                }
            } else {
                if (nsi == n / 2 - 1) l = i;
                if (nsi == n / 2) r = i;
            }
            nsi++;
        }
    }

    // cout << r << " " << l << '\n';
    int ans = 0;
    while (r < s.size() || l >= 0) {
        int rc = 0, lc = 0;
        while (r < s.size() && s[r] == 'x') {
            r++;
            rc++;
        }
        while (l >= 0 && s[l] == 'x') {
            l--;
            lc++;
        }
        // cout << rc << " " << lc << '\n';
        ans += abs(rc - lc);
        l--; r++;
    }

    cout << ans;
}
