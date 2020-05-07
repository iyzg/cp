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
const int MX = 200005;

ll T, N, A, B;
str S;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> T;
	// Shouldn't be any overflow
	while (T--) {
		cin >> N >> A >> B >> S;
		vector<pair<char, int>> groups;
		char curr = '2'; int size = 0;
		F0R(i, N) {
			if (S[i] != curr) {
				if (curr != '2') {
					groups.pb(mp(curr, size));
				}
				curr = S[i]; size = 1;
			} else size++;
			if (i == N - 1) groups.pb(mp(curr, size));
		}		
		
		// Edge case, it's only 0s
		if (sz(groups) == 1) { 
			cout << (N + 1) * B + N * A << "\n"; 
			continue;
		}
		
		// Account for the last pillar
		ll cost[sz(groups)];
		F0R(i, sz(groups)) cost[i] = 0;
		cost[0] = groups[0].s * B + (groups[0].s + 1) * A;
		FOR(i, 1, sz(groups)) {
			if (i == sz(groups) - 1) {
				cost[i] = (groups[i].s + 1) * A + groups[i].s * B;
			} else if (groups[i].f == '1') {
				cost[i] = (groups[i].s + 1) * 2 * B + groups[i].s * A;
			} else {
				// Has to be size > 2 to go back down
				if (groups[i].s == 1) {
					cost[i] = A;
				} else {
					// Just go top v. go down and back up
					cost[i] = min(groups[i].s * A + (groups[i].s - 1) * 2 * B, ((groups[i].s - 2) * A) + 4 * A + (groups[i].s - 1) * B);
				}
			}
			cost[i] += cost[i - 1];
		}
		
		cout << cost[sz(groups) - 1] << "\n";
		// F0R(i, sz(groups)) cout << cost[i] << " ";
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
