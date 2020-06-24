#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int oc[26];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for (int i = 0; i < 26; ++i) oc[i] = -1;

    for (int i = 0; i < (int)s.size(); ++i) {
        int ci = s[i] - 'a';
        if (oc[ci] == -1) oc[ci] = i;
        else {
            if (i - oc[ci] <= 2) {
                cout << oc[ci] + 1 << ' ' << i + 1;
                return 0;
            } else oc[ci] = i;
        }
    }
    cout << "-1 -1";
}
