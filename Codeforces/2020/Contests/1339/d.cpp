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

ll N, A, B, maxDepth = 0, minAns, maxAns;
vi tree[MX];
bool allEven = true;

void dfs(int v, int p, int d) {
    if (sz(tree[v]) == 1 && d % 2) allEven = false;
    if (d > maxDepth) maxDepth = d;
    trav(u, tree[v]) {
        if (u != p) dfs(u, v, d + 1);
    }
}

/* EvenDFS Vars */
set<int> cnt;
int regCount;

void cntDfs(int v, int p, int d) {
    if (sz(tree[v]) > 1) regCount++;
    else if (d > 2) {
       cnt.insert(p);
    }

    trav(u, tree[v]) {
       if (u != p) cntDfs(u, v, d + 1);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    F0R(i, N - 1) {
        cin >> A >> B;
        tree[A].pb(B);
        tree[B].pb(A);
    }
    
    int root = 1;
    FOR(i, 1, N) {
        if (sz(tree[i]) == 1) {
            root = i;
            break;
        }
    }
    dfs(root, 0, 0);
    cntDfs(root, 0, 0);
    if (allEven) {
        cout << 1 << " " << regCount + sz(cnt);
    } else {
        // max is number of non children + (unique odd depth) children
        cout << 3 << " " << regCount + sz(cnt);
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
