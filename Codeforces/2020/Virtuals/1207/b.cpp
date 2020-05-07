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
const int MX = 50;

int N, M;
int a[MX][MX], b[MX][MX];
int k; vpi ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	F0R(i, N) {
		F0R(j, M) {
			cin >> a[i][j];
		}
	}
	
	F0R(i, N - 1) {
		F0R(j, M - 1) {
			// Add one to both for "real" coords
			if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
				k++;
				ans.pb(mp(i + 1, j + 1));
				b[i][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j] = 1;
				b[i + 1][j + 1] = 1;
			}
		}
	}
	
	F0R(i, N) {
		F0R(j, M) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << k << "\n";
	F0R(i, k) {
		cout << ans[i].f << " " << ans[i].s << "\n";
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
