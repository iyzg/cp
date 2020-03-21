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

int N, M, A, B, W, ans = -1, wi = 0, fw = -1, currComp = 0, wrongCount = 0;
int group[100000], wrong[100000] = { 0 };
vi graph[100000];
vector<pair<int, pi>> wormholes;
bool done = true;

void recolor(int v, int c) {
	group[v] = c;
	if (group[v] == 1 && wrong[v]){ wrongCount--; wrong[v] = 0; }
	trav(u, graph[v])
	{
		if (group[u] != c && group[u] != -1) recolor(u, c);
	}
}

int main() {
	setIO("wormsort");
	cin >> N >> M;
	F0R(i, N)
	{
		cin >> A;
		if (A != i + 1) {
			done = false;
			wrongCount++;
			wrong[i] = 1;
		}
	}
	
	F0R(i, M)
	{
		cin >> A >> B >> W;
		--A; --B;
		wormholes.pb(mp(W, mp(A, B)));
	}
	
	sort(all(wormholes), greater<pair<int, pi>>());
	
	F0R(i, N) group[i] = -1;
	while (wrongCount)
	{
		ans = wormholes[wi].f;
		A = wormholes[wi].s.f; B = wormholes[wi].s.s;
		++wi;
		graph[A].pb(B);
		graph[B].pb(A);
		
		if (group[A] == -1 && group[B] == -1) {
			currComp++;
			group[A] = group[B] = currComp;
			if (wrong[A] && group[A] == 1) { wrongCount--; wrong[A] = 0; }
			if (wrong[B] && group[B] == 1) { wrongCount--; wrong[B] = 0; }
		} else if (group[A] == -1 && group[B] != -1) {
			group[A] = group[B];
			if (wrong[A] && group[A] == 1) { wrongCount--; wrong[A] = 0; }
		} else if (group[A] != -1 && group[B] == -1) {
			group[B] = group[A];
			if (wrong[B] && group[B] == 1) { wrongCount--; wrong[B] = 0; }
		} else {
			if (group[B] < group[A]) {
				recolor(A, group[B]);
			} else if (group[A] < group[B]) {
				recolor(B, group[A]);
			}
		}
	}
	cout << ans << "\n";	
}
