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

int Q, N;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> Q;
	while(Q--) {
		cin >> N;
		int colorCnt = 1;
		vi a(N), colors(N);
		F0R(i, N) cin >> a[i];
		bool allSame = true;
		int realN = N;
		if (a[0] == a[N - 1]) realN--;
	
		FOR(i, 1, N) {
			if (a[i] != a[i - 1]) allSame = false;
		}
		if (allSame) {
			cout << "1\n";
			F0R(i, N) cout << 1 << " ";
			cout << "\n";
		} else if (!(realN % 2) || !(N % 2)) {
			colors[0] = 0;
			FOR(i, 1, N) colors[i] = !colors[i - 1];
			cout << "2\n";
			trav(i, colors) cout << i + 1 << " ";
			cout << "\n";
		} else {
			bool bigGroup = false;
			FOR(i, 1, N) {
				if (a[i] == a[i - 1]) bigGroup = true;
			}
			
			if (bigGroup) {
				bool fixed = false;
				cout << "2\n";
				colors[0] = 0;
				FOR(i, 1, N) {
					if (a[i] == a[i - 1] && !fixed) {
						colors[i] = colors[i - 1];
						fixed = true;
					} else {
						colors[i] = !colors[i - 1];
					}
				}
			} else {
				cout << "3\n";
				colors[0] = 0;
				FOR(i, 1, N) {
					colors[i] = !colors[i - 1];
				}
				colors[N - 1] = 2;
			}
			
			trav(i, colors) cout << i + 1 << " ";
			cout << "\n";
		}
		// Add one when printing colors
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
