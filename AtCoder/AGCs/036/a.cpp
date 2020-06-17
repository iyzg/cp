#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LIM = 1e9;

ll s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    string ss = to_string(s);
    int n = ss.length();
    // cout << n << endl;

    if (n == 19) {
        cout << "0 0 1000000000 1 0 1000000000";
        return 0;
    } 

    ll si = 0;
    for (int i = 0; i < n / 2; i++) {
        if (ss[n - i - 1] == '0') continue;
        si += (10 - (ss[n - i - 1] - '0')) * powl(10, i);
        s += (10 - (ss[n - i - 1] - '0')) * powl(10, i);
        ss = to_string(s);
    }

    // cout << "SI" << si << '\n';

    n = ss.length();
    
    // x2 * y3 - x3 - y2
    ll x3 = si, y2 = 1;
    int uhalf = ceil((double)n / 2);
    string x2 = ss.substr(0, uhalf) , y3 = "1" + ss.substr(uhalf, n - uhalf);
    cout << "0 0 " << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3;
}
