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

int n, m;
// Cost to getting to each stair, final one is cost to final room

int main() {
	setIO();	
	cin >> n >> m;
	int dp[n][2], lm[n] = { 0 }, rm[n] = { 0 }, highest = 0;
	str floor;
	
	F0R(i, n)
	{
		cin >> floor;
		FOR(c, 1, m + 1)
		{
			if (floor[c]== '1')
			{
				if (!lm[n - 1 -i])
				{
					lm[n - 1 - i] = c;
					rm[n - 1 - i] = c;
				} else {
					rm[n - 1 - i] = c;
				}
			} 
		}
	}
	
	F0R(i, n)
	{
		if (lm[i]) highest = i;
	}
	
	
	//F0R(i, n) cout << lm[i] << " " << rm[i] << "\n";
	
	if (highest > 0)
	{
		dp[0][0] = rm[0] * 2;
		dp[0][1] = m + 1;
	} else {
		dp[0][0] = rm[0];
		dp[0][1] = m + 1;
	}
	
	FOR(i, 1, highest)
	{
		dp[i][0] = min(dp[i - 1][0] + 1 + (rm[i] * 2), dp[i - 1][1] + m + 2);
		dp[i][1] = min(dp[i - 1][1] + 1 + ((m + 1 - lm[i]) * 2), dp[i - 1][0] + m + 2);
		if (!lm[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
	}
	
	if (highest > 0)
	{
		dp[highest][0] = dp[highest - 1][0] + rm[highest] + 1;
		dp[highest][1] = dp[highest - 1][1] + (m + 1 - lm[highest]) + 1;
	}
	
	cout << min(dp[highest][0], dp[highest][1]);
	
	//F0R(i, n)
	//{
		//cout << dp[i][0] << " " << dp[i][1] << "\n";
	//}
	//return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
