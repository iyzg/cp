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

int N, A, B, ans = 0, currHighest = -1;
vpi mountains;
bitset<100000> visible;

int main() {
	setIO("mountains");
	visible.set();
	cin >> N;
	F0R(i, N)
	{
		cin >> A >> B;
		// Store as Y, X
		mountains.pb({B, A});
	}
	sort(all(mountains), greater<pi>());
	
	F0R(i, N)
	{
		if (visible[i]) {
			ans++;
			FOR(j, i + 1, N)
			{
				if (mountains[i].f - mountains[j].f >= abs(mountains[j].s - mountains[i].s)) visible[j] = false;
			}
		}
	}
	
	cout << ans;
}
