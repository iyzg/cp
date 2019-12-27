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
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        // cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;

template<typename T>
bool compare(const T &a,const T &b){
    return a.f < b.f;
}

int main() {
	setIO();
	ll s, b; cin >> s >> b;
	ll a[s];
	F0R(i, s) cin >> a[i];
	
	vpl bases;
	F0R(i, b)
	{
		ll b_i, g_i; cin >> b_i >> g_i;
		bases.pb(mp(b_i, g_i));
	}
	
	sort(all(bases));
	FOR(i, 1, b)
	{
		bases[i].s += bases[i - 1].s;
	}
	
	F0R(i, s)
	{
		vpl::iterator it = ub(all(bases), mp(a[i], a[i]), compare<pl>);
		if (it == bases.begin()) cout << 0 << " ";
		else cout << prev(it, 1)->s << " ";
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
