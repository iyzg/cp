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

const int MX = 100005;

int N;
ll a[MX], b[MX], dp[2][MX];


int main() {
	setIO();
	cin >> N;
	F0R(i, N) cin >> a[i];
	F0R(i, N) cin >> b[i];
	
	dp[0][0] = a[0];
	dp[1][0] = b[0];
	if (N >= 2)
	{
		dp[0][1] = dp[1][0] + a[1];
		dp[1][1] = dp[0][0] + b[1];
	}
	
	FOR(i, 2, N)
	{
		dp[0][i] = max(dp[1][i - 1] + a[i], dp[1][i - 2] + a[i]);
		dp[1][i] = max(dp[0][i - 1] + b[i], dp[0][i - 2] + b[i]);
	}
	
	cout << max(dp[0][N - 1], dp[1][N - 1]);
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
