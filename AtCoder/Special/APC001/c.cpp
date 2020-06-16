#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string zeroi;

string query(int i) {
    cout << i << endl;
    string res; cin >> res;
    return res;
}

void bsearch(int l, int r) { 
    if (l == r) {
        string ans = query(l);
    } else if (l + 1 == r) {
        if (query(r) != "Vacant")
            string ans = query(l);
    } else {
        int m = (l + r) / 2;
        string res = query(m);
        if (res == "Vacant") return;
        if ((m % 2 && res != zeroi) || (!(m % 2) && res == zeroi)) bsearch(m + 1, r);
        else bsearch(l, m - 1);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cout << 0 << endl;
    cin >> zeroi;
    if (zeroi == "Vacant") return 0;
    bsearch(1, n - 1);
}

