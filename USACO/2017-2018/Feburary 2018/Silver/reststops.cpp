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
const int MX = 1000001;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

ll L, N, F, B, X, C, ans = 0;

int main() {
	setIO("reststops");
	cin >> L >> N >> F >> B;
	vpl stops(N);
	vector<bool> isMax(N);
	F0R(i, N)
	{
		cin >> X >> C;
		stops[i] = mp(X, C);
	}
	sort(all(stops));
	ll max = 0, tf = 0, tb = 0, lastStop = 0;
	R0F(i, N)
	{
		if (stops[i].s > max) 
		{
			isMax[i] = true;
			max = stops[i].s;
		}
	}
	F0R(i, N)
	{
		if (isMax[i]) {
			tf += (stops[i].f - lastStop) * F;
			tb += (stops[i].f - lastStop) * B;
			ans += (tf - tb) * stops[i].s;
			tb = tf;
			lastStop = stops[i].f;
		}
	}

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
