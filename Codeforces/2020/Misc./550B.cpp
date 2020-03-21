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

int N, L, R, X;
ll ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> L >> R >> X;
	int diffs[N];
	F0R(i, N) cin >> diffs[i];
	F0R(mask, (1 << N)) {
		int min = -1, max = -1, numOfProbs = 0, totalDifficulty = 0;
		F0R(i, N) {
			if (mask & (1 << i)) {
				numOfProbs++;
				totalDifficulty += diffs[i];
				if (min == -1 || diffs[i] < min) {
					min = diffs[i];
				}
				if (min == -1 || diffs[i] > max) {
					max = diffs[i];
				}
			}
		}
		if (numOfProbs > 1 && totalDifficulty >= L && totalDifficulty <= R && max - min >= X) ans++;
	}
	
	cout << ans;	
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
