#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n, m;
int nxt[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        nxt[i] = n + 1;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        nxt[a] = min(nxt[a], b);
    }

    int cutoff = n + 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cutoff == i) {
            ans++;
            cutoff = n + 1;
        }
        cutoff = min(cutoff, nxt[i]);
    }
    cout << ans;
}
