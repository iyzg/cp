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

int cnt[26] = { 0 };
ll dp[26][5000] = {{ 0 }};
set<pair<int, pair<char, char>>> uniquepair;
set<pair<int, pair<char, char>>> removed;
ld ans = 0;

int main() {
	setIO();
	str line; cin >> line;
	F0R(i, sz(line))
	{
		cnt[line[i] - 97]++;
		F0R(j, i)
		{
			// Fix this because if there are an odd number of occurences, it'll still think its unique
			// Remove if it's no longer unique
			if (removed.count(mp(i - j, mp(line[j], line[i])))) continue;
			else if (uniquepair.insert(mp(i - j, mp(line[j], line[i]))).s)
			{
				dp[line[j] - 97][i - j - 1]++;
			} else {
				dp[line[j] - 97][i - j - 1]--;
				uniquepair.erase(mp(i - j, mp(line[j], line[i])));
				removed.insert(mp(i - j, mp(line[j], line[i])));
			}
		}
	}
	
	trav(i, uniquepair)
	{
		cout << i.f << " " << i.s.f << " " << i.s.s << "\n";
	}
		
	F0R(i, 26)
	{
		if (!cnt[i]) continue;
		else if (cnt[i] == 1) ans++;
		else {
			int best = 0;
			F0R(j, 5000)
			{
				if (dp[i][j] > best) best = dp[i][j];
			}
			
			ans += (ld)best / sz(line);
			// ans is actually max number of combos/sz(line) ?
			cout << "Added " << best << " from letter " << i << "\n";
		}
	}
	
	cout << setprecision(10) << fixed << ans / sz(line);
	
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
