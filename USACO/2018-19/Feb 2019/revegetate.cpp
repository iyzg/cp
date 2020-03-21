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

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, M, A, B, P[100005];
vi D[100001], S[100001];
int ans = 0;
bool invalid = false;
char T;

void dfs(int v, int c) {
	P[v] = c;
	trav(u, D[v])
	{
		if (P[v] == P[u]) invalid = true;
		if (P[u] == -1) dfs(u, !c);
	}
	
	trav(u, S[v])
	{
		if (P[v] != P[u] && P[u] != -1) invalid = true;
		if (P[u] == -1) dfs(u, c);
	}
}

int main() {
	setIO("revegetate");
	cin >> N >> M;
	F0R(i, 100005) P[i] = -1;
	F0R(i, M)
	{
		cin >> T >> A >> B;
		if (T == 'S') { S[A].pb(B); S[B].pb(A); }
		if (T == 'D') { D[A].pb(B); D[B].pb(A); }
	}
	
	FOR(i, 1, N + 1)
	{
		if (P[i] == -1) {
			dfs(i, 0);
			++ans;
		}
	}
	
	if (invalid) {
		cout << 0;
		return 0;
	}
	
	cout << 1;
	while(ans--)
	{
		cout << 0;
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
