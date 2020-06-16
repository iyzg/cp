#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n, m, k;
vector<int> fconn[N];
vector<int> bconn[N];

int curGroup = 0;
int group[N], groupSize[N + 5];

bitset<N> valid;

void color(int v) {
    group[v] = curGroup;
    groupSize[curGroup]++;
    for (auto u : fconn[v]) {
        if (!group[u]) color(u);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        fconn[a].push_back(b);
        fconn[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        bconn[a].push_back(b);
        bconn[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        curGroup++;
        if (!group[i]) color(i);
    }

    for (int i = 0; i < n; i++) {
        int ans = groupSize[group[i]] - 1;
        valid.set();
        for (auto u : fconn[i]) {
            valid[u] = false;
            ans--;
        }

        for (auto u : bconn[i]) {
            if (group[u] == group[i] && valid[u]) {
                ans--;
            }
        }
        cout << ans << ' ';
    }
}
