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

str weightl;
vi weights;
int m;

int main() {
	setIO();
	cin >> weightl;
	F0R(i, sz(weightl))
	{
		if (weightl[i] == '1') weights.pb(i + 1);
	}
	
	cin >> m;
	if (sz(weights) == 1)
	{
		if (m == 1) cout << "YES\n" << weights[0];
		else cout << "NO";
		return 0;
	}
	
	if (sz(weights) >= 2)
	{
		int a, b;
		a = weights[sz(weights) - 2];
		b = weights[sz(weights) - 1];
		if (((a * b / __gcd(a, b) / a) - 1) * 2 >= m)
		{
			cout << "YES\n";
			int time = 1;
			while (time <= m)
			{
				if (time % 2) cout << a << " ";
				else cout << b << " ";
				++time;
			}
			return 0;
		}
	}

	if (sz(weights) >= 3)
	{
		str sequence = "";
		int ai = 0, bi = 1;
		ll left = 0, right = 0;
		int times = 1;
		while (ai != sz(weights) && bi != sz(weights))
		{
			if (times % 2)
			{
				if (left + weights[ai] > right) 
				{
					left += weights[ai];
				} else {
					ai = bi + 1;
					while (ai < sz(weights) && left + weights[ai] <= right) ai++;
					if (ai == sz(weights)) break;
					else {
						left += weights[ai];
					}
				}
				sequence += to_string(weights[ai]) + " ";
			} else {
				if (right + weights[bi] > left)
				{
					right += weights[bi];
				} else {
					bi = ai + 1;
					while (bi < sz(weights) && right + weights[bi] <= left) bi++;
					if (bi == sz(weights)) break;
					else {
						right += weights[ai];
					}
				}
				sequence += to_string(weights[bi]) + " ";
			}
			times++;
		}
		
		if (times >= m)
		{
			cout << "YES\n" << sequence;
		}
	}
			
			
	
	// Another one here
	
	
	
	
	cout << "NO";
	
	
	
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
