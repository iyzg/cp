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

int main() {
	setIO();
	int T; cin >> T;
	F0R(t, T)
	{
		ll n, m, a, b;
		cin >> n >> m >> a >> b;
		vl easy, hard;
		ll diff[n], req[n];
		F0R(i, n) cin >> diff[i];
		F0R(i, n) cin >> req[i];
		
		F0R(i, n)
		{
			if (diff[i]) hard.pb(req[i]);
			else easy.pb(req[i]);
		}
		
		sort(all(easy));
		sort(all(hard));
		queue<ll> curreasy, currhard;
		F0R(i, sz(easy))
		{
			curreasy.push(easy[i]);
		}
		
		F0R(i, sz(hard))
		{
			currhard.push(hard[i]);
		}
		
		ll curr = 0, solved = 0;
		while (curr < m)
		{
			if (!sz(currhard) && !sz(curreasy)) break;
			if (sz(currhard) && sz(curreasy))
			{
				if (curr + a <= m && curr + a <= curreasy.front() && curr + a < currhard.front())
				{
					solved++;
					curreasy.pop();
					curr += a;
				} else {
					break;
				}
			} else if (sz(currhard)) {
				if (curr + b <= m && curr + b <= currhard.front())
				{
					solved++;
					currhard.pop();
					curr += b;
				} else {
					break;
				}
			} else {
				if (curr + a <= m && curr + a <= curreasy.front())
				{
					solved++;
					curreasy.pop();	
					curr += a;
				} else {
					break;
				}
			}	
		}
		cout << solved << "\n";
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
