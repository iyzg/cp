#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n, m;
int pre[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        pre[a]++; pre[b]--;
    }
    
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += pre[i];
        if (tot % 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}

