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
const int MX = 100001;

int N, X, Y, T;
// 0 Repaired, 1 fine, 2 broke
int status[MX], par[MX] = { 0 };
vpi graph[MX];
vi ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	status[1] = 1;
	F0R(i, N - 1) 
	{
		cin >> X >> Y >> T;
		graph[X].pb(mp(Y, T));
		graph[Y].pb(mp(X, T));
	}
	
	queue<int> q;
	stack<int> st;
	q.push(1);
	st.push(1);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		trav(u, graph[v])
		{
			if (u.f != par[v]) {
				par[u.f] = v;
				q.push(u.f);
				st.push(u.f);
				status[u.f] = u.s;
			}
		}
	}
	
	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		if (status[v] == 2) {
			ans.pb(v);
			status[par[v]] = 0;
		} else if (status[v] == 0) {
			status[par[v]] = 0;
		}
	}
	
	cout << sz(ans) << "\n";
	trav(i, ans) cout << i << " ";
	// BFS, set status of nodes then reverse BFS to get fixed roads
	
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
