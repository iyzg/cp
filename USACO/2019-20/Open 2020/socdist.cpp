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

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

ll N, M, A, B;
vpl grass;

bool fit(ll dist) {
    ll cows = 0, lastCow = -1;
    trav(i, grass) {
        if (lastCow == -1) {
            lastCow = i.f;
            cows++;
        }
        
        if (i.s < lastCow + dist) continue;
        lastCow = max(i.f, lastCow + dist);
        cows++;
        while(lastCow + dist <= i.s) {
            lastCow += dist;
            cows++;
        }
        
        if (cows >= N) break;
    }
    return cows >= N;
}

ll binSearch(ll l, ll r) {
    if (l == r) return r;
	if (l + 1 == r) {
		if (fit(r)) return r;
		return l;
	}
	ll m = (l + r) / 2;
	if (fit(m)) return binSearch(m, r);
	else return binSearch(1, m - 1);
}

int main() {
	setIO("socdist");
    cin >> N >> M;
    F0R(i, M) {
        cin >> A >> B;
        grass.pb(mp(A, B));
    }
    sort(all(grass));
    cout << binSearch(1, grass[M - 1].s);
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
