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

int N, K1, K2, k_i, fights = 0;
str deckOne, deckTwo;
set<pair<str, str>> positions;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> K1;
	F0R(i, K1) 
	{
		cin >> k_i;
		--k_i;
		deckOne += to_string(k_i);
	}
	cin >> K2;
	F0R(i, K2)
	{
		cin >> k_i;
		--k_i;
		deckTwo += to_string(k_i);
	}
	
	while (sz(deckOne) && sz(deckTwo))
	{
		fights++;
		int a = deckOne[0] - '0', b = deckTwo[0] - '0';
		if (!(positions.insert({deckOne, deckTwo}).s)) {
			cout << -1;
			return 0;
		}
		
		if (a > b) {
			deckOne += deckTwo[0];
			deckOne += deckOne[0];
		} else {
			deckTwo += deckOne[0];
			deckTwo += deckTwo[0];
		}
		
		deckOne.erase(0, 1);
		deckTwo.erase(0, 1);
		// Make both lose first char
	}
	
	cout << fights << " ";
	sz(deckOne) ? cout << 1 : cout << 2;
	
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
