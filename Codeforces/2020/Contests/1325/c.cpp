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

int N, U, V, currMin = 0, currMax;
vi tree[MX];
map<pi, int> edgeWeights;
vector<pi> edgeOrder;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	currMax = N - 2;
	
	F0R(i, N - 1) {
		cin >> U >> V;
		tree[U].pb(V);
		tree[V].pb(U);
		if (V < U) swap(U, V);
		edgeOrder.pb(mp(U, V));
	}
	
	int startNode = -1;
	FOR(i, 1, N + 1) {
		if (sz(tree[i]) > 1) {
			startNode = i;
			break;
		}
	}
	if (startNode == -1) startNode = 1;
	
	queue<int> q;
	vector<bool> used(MX);
	vi p(MX);
	q.push(startNode);
	used[startNode] = true;
	p[startNode] = -1;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		trav(u, tree[v]) {
			if (!used[u]) {
				q.push(u);
				used[u] = true;
				p[u] = v;
			}
		}
		if (p[v] != -1) {
			if (sz(tree[v]) == 1) {
				if (p[v] < v) edgeWeights[mp(p[v], v)] = currMin;
				else edgeWeights[mp(v, p[v])] = currMin;
				currMin++; 
			} else {
				if (p[v] < v) edgeWeights[mp(p[v], v)] = currMax;
				else edgeWeights[mp(v, p[v])] = currMax;
				currMax--; 
			}
		}
			
	}
	
	F0R(i, N - 1) {
		cout << edgeWeights[mp(edgeOrder[i].f, edgeOrder[i].s)] << "\n";
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
