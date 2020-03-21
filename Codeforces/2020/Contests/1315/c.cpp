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

int T, N;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> N;
		vi b(N), taken;
		vi avail;
		F0R(i, N) {
			cin >> b[i];
			taken.pb(b[i]);
		}
		sort(all(taken));
		int ti = 0;
		FOR(i, 1, N * 2 + 1) {
			if (ti < N && i == taken[ti]) {
				ti++;
				continue;
			}
			else avail.pb(i);
		}
		
		vi results(N * 2);
		bool failed = false;
		F0R(i, N)
		{
			auto low = lb(all(avail), b[i]);
			if (low == avail.end()) {
				failed = true;
				break;
			}
			results[2 * i] = b[i];
			results[2 * i + 1] = avail[low - avail.begin()];
			avail.erase(avail.begin() + (low - avail.begin()));
		}
		
		if (!failed) {
			trav(i, results) cout << i << " ";
			cout << "\n";
		} else {
			cout << "-1\n";
		}
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
