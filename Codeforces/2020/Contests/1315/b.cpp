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

int T, A, B, P;
str S;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> A >> B >> P >> S;
		vi costs(sz(S));
		costs[sz(S) - 1] = 0;
		if (S[sz(S) - 2] == 'A') costs[sz(S) - 2] = A;
		else costs[sz(S) - 2] = B;
		R0F(i, sz(S) - 2) {
			if (S[i] == S[i + 1]) costs[i] = costs[i + 1];
			else {
				if (S[i] == 'A') costs[i] = costs[i + 1] + A;
				else  costs[i] = costs[i + 1] + B;
			}
		}
		F0R(i, sz(S)) {
			if (costs[i] <= P) {
				cout << i + 1 << "\n";
				break;
			}
		}
		// Edge case, if he can't afford anything then he must walk to the end
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
