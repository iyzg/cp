#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100000;

int n, m;

vector<int> conn[N];
ll parent[N], sz[N];

// DSu
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto& i : edges) {
        cin >> i.first >> i.second;
        --i.first, --i.second;
    }
    reverse(edges.begin(), edges.end());

    for (int i = 0; i < n; i++)
        make_set(i);
    
    vector<ll> diff;
    for (auto edge : edges) {
        int fg = find_set(edge.first), sg = find_set(edge.second);
        if (fg != sg) {
            diff.push_back(sz[fg] * sz[sg]);
            union_sets(fg, sg);
        } else {
            diff.push_back(0);
        }
    }

    reverse(diff.begin(), diff.end());
    
    ll ans = 0;
    for (auto i : diff) {
        ans += i;
        cout << ans << '\n';
    }
}
