#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    int lb = 0, rb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') lb++;
        else {
            if (lb) lb--;
            else rb++;
        }
    }

    for (int i = 0; i < rb; i++) cout << '(';
    cout << s;
    for (int i = 0; i < lb; i++) cout << ')';
    return 0;
}
