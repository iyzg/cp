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

int N, M;
str S;
map<int, int> isParent;
// moves it takes, spot
set<pi> pref;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> S;
	// Find min moves to get to a square then store the preceding node later
	int dp[N + 1], p[N + 1];
	vi firstValidParents;
	
	F0R(i, N + 1) {
		dp[i] = 0;
		p[i] = 0;
	}
	pref.insert({0, 0});
	
	F0R(i, N) {
		if (S[i] == '1') dp[i] = -1;
	}
	
	FOR(i, 1, N + 1) {
		if (i > M && dp[i - M - 1] != -1) {
			pref.erase({dp[i - M - 1], i - M - 1});
		}
		
		if(dp[i] != -1 && sz(pref)) {
			dp[i] = pref.begin()->f + 1;
			p[i] = pref.begin()->s;
		}
		
		if (dp[i] > 0) {
			pref.insert({dp[i], i});
		}
	}
	
	if (!dp[N]) {
		cout << -1;
		return 0;
	}
	
	int curr = N;
	vi dists;
	while(curr != 0) {
		dists.pb(curr - p[curr]);
		curr = p[curr];
	}
	reverse(all(dists));
	trav(i, dists) cout << i << " ";
	// F0R(i, N + 1) cout << dp[i] << " ";
	// cout << "\n";
	
	// firstValidParents.pb(N);
	// FOR(i, 1, sz(firstValidParents)) cout << firstValidParents[i] - firstValidParents[i - 1] << " ";
	
	// int curr = 0;
	// while(curr != N) {
		// FOR(i, 1, M + 1) {
			// if (curr + i <= N && dp[curr + i] == dp[curr] + 1 && (isParent.count(curr + i) || curr + i == N)) {
				// curr = curr + i;
				// cout << i << " ";
				// break;
			// }
		// }
	// }
	
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
