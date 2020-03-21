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

int N, A[100000];

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int solve_min() {
	if (A[N-2]-A[0] == N-2 && A[N-1]-A[N-2]>2) return 2;
	if (A[N-1]-A[1] == N-2 && A[1]-A[0]>2) return 2;
	int i, j = 0, best = 0;
	for (i = 0; i < N; i++) {
		while(j < N - 1 && A[j + 1] - A[i] <= N - 1) j++;
		best = max(best, j - i + 1);
	}
	return N - best;
}

int main() {
	setIO("herding");
	cin >> N;
	F0R(i, N) cin >> A[i];
	sort(A, A + N);
	
	
	// Minimum
	cout << solve_min() << "\n";;
	// Maximum
	int freeSlots = A[N - 1] - A[0] - 1;
	cout << max(freeSlots - (A[N - 1] - A[N - 2]) - (N - 3), freeSlots - (A[1] - A[0]) - (N - 3));
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
