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
 
int N, M, u_i, v_i;
 
vi graph[MX];
int len[MX], conn[MX];
 
ll ans = 1;
 
void updateLen(int v) {
	trav(child, graph[v])
	{
		len[child] = max(len[child], len[v] + 1);
	}
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	F0R(i, N) 
	{
		len[i] = 1;
		conn[i] = 0;
	}
	
	F0R(i, M)
	{
		cin >> u_i >> v_i;
		u_i--; v_i--;
		conn[u_i]++; conn[v_i]++;
		if (v_i < u_i) swap(u_i, v_i);
		graph[u_i].pb(v_i);
	}
	
	// This is the slow part 
	F0R(i, N) updateLen(i);
	
	F0R(i, N) ans = max(ans, (ll)len[i] * conn[i]);	
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
