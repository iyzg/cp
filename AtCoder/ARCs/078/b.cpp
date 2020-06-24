#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int n, snuke;
vector<int> conn[N];
int par[N], depth[N];

void init(int v, int p, int d) {
    depth[v] = d;
    par[v] = p;
    for (auto u : conn[v]) {
        if (u != par[v]) init(u, v, d + 1);
    }
}

int black = 0;
void count(int v) {
    ++black;
    for (auto u : conn[v]) {
        if (u != par[v] && u != snuke) count(u);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    snuke = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }

    init(0, -1, 0);

    int times = (depth[snuke] - 1) / 2;
    for (int i = 0; i < times; ++i) snuke = par[snuke];

    count(0);
    if (black > n - black) cout << "Fennec";
    else cout << "Snuke";
}
