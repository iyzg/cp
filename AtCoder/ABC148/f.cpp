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
const int MX = 100005;

int N, U, V, A, B;
vi tree[MX];
int parent[MX], depth[MX], maxDepth[MX];
ll ans;

int dfs(int v, int p) {
    depth[v] = depth[p] + 1;
    int maxD = depth[v];
    trav(u, tree[v]) {
        if (!depth[u]) {
            parent[u] = v;
            maxD = max(maxD, dfs(u, v));
        }
    }
    maxDepth[v] = maxD;
    return maxD;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> U >> V;
    F0R(i, N - 1) {
        cin >> A >> B;
        tree[A].pb(B);
        tree[B].pb(A);
    }
    
    dfs(V, 0);
    ans += (depth[U] - depth[V] - 1) / 2;
    F0R(i, ans) U = parent[U];
    if (depth[U] - (depth[V] + ans) == 2) ans++;
    ans += maxDepth[U] - depth[U];
    cout << ans;
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
