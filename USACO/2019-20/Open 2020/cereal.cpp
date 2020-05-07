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
const int MX = 100005;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, M, A, B;
int eaten[MX], ans[MX];

int main() {
	setIO("cereal");
    cin >> N >> M;
    vpi cows;
    F0R(i, M + 5) eaten[i] = -1;
    F0R(i, N) {
        cin >> A >> B;
        cows.pb(mp(A, B));
    }
    
    ans[N - 1] = 1;
    eaten[cows[N - 1].f] = N - 1;
    R0F(i, N - 1) {
        ans[i] = ans[i + 1] + 1;
        if (eaten[cows[i].f] == -1) {
            eaten[cows[i].f] = i;
        } else {
            int nextCow = eaten[cows[i].f];
            eaten[cows[i].f] = i;
            // While the spot is taken or if both spots are taken
            while(nextCow != -1) {
                if(eaten[cows[nextCow].s] != -1 && eaten[cows[nextCow].s] < nextCow) {
                    // cout << "HERE\n";
                    ans[i]--;
                    nextCow = -1;
                } else if (eaten[cows[nextCow].s] == -1) {
                    // cout << "HERE2\n";
                    eaten[cows[nextCow].s] = nextCow;
                    break;
                } else {
                    // cout << "HERE3\n";
                    int currCow = nextCow;
                    nextCow = eaten[cows[currCow].s];
                    eaten[cows[currCow].s] = currCow;
                    // cout << "NEXT IS " << nextCow << "\n";
                }
            }
        }
    }
    
    // FOR(i, 1, M + 1) cout << eaten[i] << " ";
    // cout << endl;
    F0R(i, N) cout << ans[i] << "\n";
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
