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

int N, K, ans = -1;
vi trees(1000);

int main() {
	setIO("berries");
	cin >> N >> K;
	F0R(i, N) cin >> trees[i];
	sort(all(trees), greater<int>());
	FOR(b, 1, trees[0])
	{
		vi baskets;
		F0R(i, N)
		{
			int A = trees[i];
			while (A > 0)
			{
				if (A >= b) { baskets.pb(b); A -= b; }
				else { baskets.pb(A); A = 0; }
			}
		}
		
		sort(all(baskets), greater<int>());
		if (sz(baskets) < K) continue;
		int berries = 0;
		FOR(i, K / 2, K) berries += baskets[i];
		ans = max(berries, ans);
	}
	cout << ans << "\n";
}

