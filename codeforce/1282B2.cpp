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
		ll n, p, k;
		cin >> n >> p >> k;
		ll a[n];
		ll dp[n] = { 0 };
		F0R(i, n) cin >> a[i];
		sort(a, a + n);
		ll ans = 0;
		F0R(i, k - 1)
		{
			if (i >= n) break;
			if (i == 0) dp[i] = a[i];
			else dp[i] += a[i] + dp[i - 1];
			if (dp[i] <= p && i + 1 > ans) ans = i + 1;
		}
		
		if (k - 1 < n) dp[k - 1] = a[k - 1];
		if (dp[k - 1] <= p && k > ans) ans = k;

		
		FOR(i, k, n)
		{
			dp[i] = min(dp[i - 1] + a[i], dp[i - k] + a[i]);
			if (dp[i] <= p && i + 1 > ans) ans = i + 1;
		}
		
		cout << ans << "\n";
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
