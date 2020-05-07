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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MX = 1000001;

ll X, Y;

ll factorization(ll x) {
	if (x == 1) return x;
	else return ((x % MOD) * (factorization(x - 1) % MOD)) % MOD;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> X >> Y;
	if ((X + Y) % 3) {
		cout << "0";
		return 0;
	} else {
		int rightMoves = (X - (Y - X)) / 3;
		int upMoves = X - (2 * rightMoves);
		int totalMoves = rightMoves + upMoves;		
		
		ll total = 1;
		FOR(i, 2, totalMoves + 1) {
			total = ((total % MOD) * (i % MOD) % MOD);
		}
		cout << total << " " << rightMoves << " " << upMoves << "\n";
		cout << total << " " << factorization(rightMoves) << "\n";
		cout << total / (factorization(rightMoves) * factorization(upMoves));
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
