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
const int MX = 20;

int N;
int a[MX];
int x[MX][MX], y[MX][MX];

int counter(int X) {
    if (X == 0) return 0;
    return counter(X >> 1) + (X & 1);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    FOR(i, 1, N + 1) {
        cin >> a[i];
        FOR(j, 1, a[i] + 1) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    
    int ans = 0;
    
    for(int bits = 1; bits < (1 << N); bits++) {
        bool ok = true;
        for(int i = 1; i <= N; i++) {
            // If it's not included as an honest person, not worth checking.
            if(!(bits & (1 << (i - 1)))) continue;
            for(int j = 1; j <= a[i]; j++) {
                if (((bits >> (x[i][j] - 1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if (ok) ans = max(ans, counter(bits));
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
