#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    cout << 26 * (s.size() + 1) - s.size();
    return 0;
}
