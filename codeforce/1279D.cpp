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

ll n, k, toy, num = -1, den = -1;
map<ll, ll> m;

const ll MOD = 998244353;

long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

int main() {
	setIO();
	cin >> n;
	
	vl toys[n];
	pair<ll, ll> kf[n];
	
	F0R(i, n)
	{
		cin >> k;
		F0R(j, k)
		{
			cin >> toy;
			toys[i].pb(toy);
			m[toy]++;
		}
	}
	
	F0R(i, n)
	{
		F0R(j, sz(toys[i]))
		{
			kf[i].f = 1;
			kf[i].s = n;		
			kf[i].f *= m[toys[i][j]];
			kf[i].s = ((kf[i].s % MOD) * (sz(toys[i]) % MOD) % MOD);
			kf[i].s = ((kf[i].s % MOD) * (n % MOD) % MOD);
			if (num == -1 && den == -1)
			{
				num = kf[i].f;
				den = kf[i].s;
			} else {
				if (kf[i].s == den) num += kf[i].f;
				else {
					ll nd = den * kf[i].s / __gcd(den, kf[i].s);
					num *= nd / den;
					kf[i].f *= nd / kf[i].s;
					den = nd;
					num += kf[i].f;
				}
			}
		}
	}			
	
	if (__gcd(num, den) != 1)
	{
		ll gcd = __gcd(num, den);
		den /= gcd;
		num /= gcd;
	}
		
	cout << ((num % MOD) * (inv(den, MOD) % MOD)) % MOD;
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
