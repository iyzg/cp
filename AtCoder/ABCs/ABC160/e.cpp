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

ll X, Y, A, B, C;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> X >> Y >> A >> B >> C;
    vl a(A), b(B), c(C);
    F0R(i, A) cin >> a[i];
    F0R(i, B) cin >> b[i];
    F0R(i, C) cin >> c[i];
    sort(all(a), greater<ll>()); sort(all(b),greater<ll>()); sort(all(c), greater<ll>());
    
    int ai = 0, bi = 0;
    ll ans = 0;
    vl reds, greens;
    F0R(i, X) reds.pb(a[i]);
    F0R(i, Y) greens.pb(b[i]);
    sort(all(reds)); sort(all(greens));
    F0R(i, C) {
        if (ai < X && bi < Y) {
            if (reds[ai] < greens[bi] && reds[ai] < c[i]) {
                reds[ai++] = c[i];
            } else if (greens[bi] <= reds[ai] && greens[bi] < c[i]) {
                greens[bi++] = c[i];
            }
        } else if (ai < X) {
            if (reds[ai] < c[i]) reds[ai++] = c[i];
        } else if (bi < Y) {
            if (greens[bi] < c[i]) greens[bi++] = c[i];
        }
    }
    
    trav(i, reds) ans += i;
    trav(i, greens) ans += i;
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
