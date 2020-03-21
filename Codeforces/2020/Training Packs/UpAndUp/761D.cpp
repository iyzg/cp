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

ll N, L, R, last;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> L >> R;
	vl a(N), c(N);
	F0R(i, N) cin >> a[i];
	F0R(i, N) cin >> c[i];
	
	vpl order(N);
	F0R(i, N) {
		// Where it belongs in terms of compressed you put (a value, original index)
		order[c[i] - 1] = mp(a[i], i);
	}
	//F0R(i, N) cout << order[i].f << " " << order[i].s << "\n";
	vl b(N);
	F0R(i, N) {
		// Some check to see if any valid numbers are in bounds or eturn -1
		if (i == 0) {
			b[order[i].s] = L;
			last = L - order[i].f;
		} else {
			//cout << last << "\n";
			int min = last + 1  + order[i].f;
			min = max((ll)min, L);
			if (min > R) {
				cout << -1;
				return 0;
			}
			b[order[i].s] = min;
			last = min - order[i].f;
		}
	}
	
	F0R(i, N) cout << b[i] << " ";
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
