#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 200005;

int t[4*MX] = { 0 };

struct Segtree {
    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    int get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(get_max(v*2, tl, tm, l, min(r, tm)),
               get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
};

int N, A, B;
int a[MX], best[MX], ans[MX];
vector<int> tree[MX];
map<int, int> compressed;
Segtree segtree;

void dfs(int v, int p) {
    // cout << "on node: " << v << "\n";
    int before = best[a[v]];
    ans[v] = 1;
    int ext = segtree.get_max(1, 0, N - 1, 0, a[v] - 1) + 1;
    chmax(ans[v], ext);
    
    if (ans[v] > best[a[v]]) {
        segtree.update(1, 0, N - 1, a[v], ans[v]);
        best[a[v]] = ans[v];
    }
    chmax(ans[v], ans[p]);
    // cout << v << ": " << best[a[v]] << "\n";
        
    for (auto& u : tree[v]) {
        if (u != p) dfs(u, v);
    }
    
    best[a[v]] = before;
    segtree.update(1, 0, N - 1, a[v], before);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < N; i++) compressed[a[i]];
    
    int pos = 0;
    for (auto& i : compressed) {
        i.second = pos++;
    }
    
    for (int i = 0; i < N; i++) a[i] = compressed[a[i]];
    
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        A--; B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    segtree.build(best, 1, 0 , N - 1);
    
    dfs(0, -1);
    for (int i = 0; i < N; i++) cout << ans[i] << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
