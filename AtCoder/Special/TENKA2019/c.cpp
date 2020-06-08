#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;

int n;
string s;
int white[N], black[N];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') white[i]++;
        else black[i]++;
        if (i) {
            white[i] += white[i - 1];
            black[i] += black[i - 1];
        }
    }

    int ans = min(white[n - 1], black[n - 1]);
    for (int i = 0; i < n; i++) {
        int change = black[i] + white[n - 1] - white[i];
        ans = min(ans, change);
    }
    cout << ans << "\n";
    return 0;
}
