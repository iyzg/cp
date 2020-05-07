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
const int MX = 200005;

int N, M, U, V, K, J, L;
vi tree[MX];
int depth[MX], par[MX];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : tree[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(N);
    tout.resize(N);
    timer = 0;
    L = ceil(log2(N));
    up.assign(N, vector<int>(L + 1));
    dfs(root, root);
}

void getDepth(int v, int d) {
	depth[v] = d;
	trav(u, tree[v]) {
		if (!depth[u]) {
			getDepth(u, d + 1);
			par[u] = v;
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	F0R(i, N - 1) {
		cin >> U >> V;
        U--; V--;
		tree[U].pb(V);
		tree[V].pb(U);
	}
    
    preprocess(0);
    getDepth(0, 1);
    
	F0R(i, M) {
		cin >> K;
		vi query(K);
		int maxDepth = 0, toVisit = 1;
		F0R(j, K) {
			cin >> query[j];
            query[j]--;
			if (depth[query[j]] > maxDepth) {
				maxDepth = depth[query[j]];
				toVisit = query[j];
			}
		}
		
        bool invalidQ = false;
		trav(j, query) {
            int common = lca(j, toVisit);
            if (abs(depth[common] - depth[j]) > 1) {
                invalidQ = true;
                cout << "NO\n";
                break;
            }
		}
		
		if (!invalidQ) cout << "YES\n";
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
