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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000001;

int N, cseg = 0;
str s_i;
vector<pair<char, int>> segs;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> s_i;
	segs.pb(mp(s_i[0], 1));
	FOR(i, 1, N)
	{
		if (s_i[i] == segs[cseg].f) segs[cseg].s++;
		else {
			cseg++;
			segs.pb(mp(s_i[i], 1));
		}
	}
	
	F0R(i, sz(segs))
	{
		if (segs[i].f != 'a' && segs[i].f != 'e' && segs[i].f != 'i' && segs[i].f != 'o' && segs[i].f != 'u' && segs[i].f != 'y') {
			F0R(j, segs[i].s) cout << segs[i].f;
		} else {
			if (segs[i].f == 'e' && segs[i].s == 2) {
				cout << "ee";
			} else if (segs[i].f == 'o' && segs[i].s == 2) {
				cout << "oo";
			} else {
				cout << segs[i].f;
			}
		}
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
