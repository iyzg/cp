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
const int MX = 200000;

int N, K;
ll ans = 0, possibilities = 1, currGroup = 0;
int groupSize[MX];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	vi a(N), calcMax(N);
	F0R(i, N) {
		cin >> a[i];
		calcMax[i] = a[i];
	}
	
	sort(all(calcMax), greater<int>()); 
	F0R(i, K) {
		ans += calcMax[i];
	}
	
	F0R(i, N) {
		groupSize[currGroup]++;
		if (a[i] > N - K) {
			if (currGroup < K - 1) currGroup++;
			else {
				break;
			}
		}
	}
		
		
		
		//if (a[i] > N - K && currGroup < K - 1) {
			//if (i < N - 2 && currGroup == 0 && a[i + 1] > N - K) groupSize[0] = 1;
			//if (i < N - 2 && currGroup == K - 2 && a[i + 1] > N - K) {
				//groupSize[K - 1] = 1;
				//break;
			//}
			//currGroup++;
		//}
	//}
	
	if (currGroup > 0) {
		//if (a[0] <= N - K) groupSize[0]--;
		//if (a[N - 1] <= N - K) groupSize[currGroup]--;
		FOR(i, 1, K) {
			if (groupSize[i] != 0) possibilities = ((possibilities % MOD) * (groupSize[i] % MOD)) % MOD;
		}
		// Don't multiply if 0
	}
	
	cout << ans << " " << possibilities << "\n";
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
