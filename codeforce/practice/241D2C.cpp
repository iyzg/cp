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

bool sortinrev(const pair<pair<int,int>, int> &a,  
               const pair<pair<int,int>, int> &b) 
{ 
       return (a.f.f > b.f.f); 
} 

int main() {
	setIO();
	int n; cin >> n;
	vector<pair<pi, int>> guests;
	F0R(i, n)
	{
		int c, p; cin >> c >> p;
		guests.pb(mp(mp(p, c), i + 1));
	}
	
	sort(all(guests), sortinrev);
	
	//F0R(i, n)
	//{
		//cout << guests[i].f.f << " " << guests[i].f.s << "\n";
	//}
	
	int k; cin >> k;
	vpi tables;
	vector<bool> taken(k);
	F0R(i, k)
	{
		int r; cin >> r;
		taken[i] = false;
		tables.pb(mp(r, i + 1));
	}
	
	sort(all(tables));
	
	ll ans = 0;
	vpi pairs;
	F0R(i, n)
	{
		//cout << guests[i].f.f << " " << guests[i].f.s << " ";
		auto index = (lb(all(tables), mp(guests[i].f.s, 0)) - tables.begin());
		//cout << index << "\n";
		if (index == sz(tables)) continue;
		while (index < sz(tables))
		{
			if (taken[index]) 
			{
				++index;
				continue;
			}
			taken[index] = true;
			ans += guests[i].f.f;
			pairs.pb(mp(guests[i].s, tables[index].s));
			break;
		}
	}
	
	cout << sz(pairs) << " " << ans << "\n";
	trav(i, pairs)
	{
		cout << i.f << " " << i.s << "\n";
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
