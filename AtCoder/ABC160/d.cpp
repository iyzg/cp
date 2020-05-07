#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 5000;

int N, X, Y;
vi tree[MX];
map<pi, int> dists;
int p;
bitset<MX> vis;
int lengths[MX] = {0};


void dfs(int v, int d) {
    vis[v] = 1;
    if (p < v) {
        if (!dists.count(mp(p, v))) dists[mp(p, v)] = d;
        else dists[mp(p, v)] = min(dists[mp(p, v)], d);
    } else {
        if (!dists.count(mp(v, p))) dists[mp(v, p)] = d;
        else dists[mp(v, p)] = min(dists[mp(v, p)], d);
    }

    
    trav(u, tree[v]) {
        if (!vis[u]) dfs(u, d + 1);
    }
}

void bfs() {
    vis.reset();
    queue<int> q;
    q.push(p);
    vis[p] = 1;
    vector<int> d(MX);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : tree[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                if (u > p) {
                    lengths[d[u] - d[p]]++;
                }
            }
        }
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> X >> Y;
    tree[X].pb(Y);
    tree[Y].pb(X);
    FOR(i, 1, N + 1) {
        if (i < N) {
            tree[i].pb(i + 1);
            tree[i + 1].pb(i);
        }
    }
    
    FOR(i, 1, N + 1) {
        vis.reset();
        p = i;
        bfs();
    }
    
    FOR(i, 1, N) {
        cout << lengths[i] << "\n";
    }
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
