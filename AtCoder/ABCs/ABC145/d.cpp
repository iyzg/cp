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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll MX = 2000005;

namespace Modop {
    ll modAdd(ll a, ll b) {
        return (a + b) % MOD;
    }
    
    ll modSub(ll a, ll b) {
        return (((a - b) % MOD) + MOD) % MOD;
    }
    
    ll modMul(ll a, ll b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    ll modExp(ll base, ll power) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % MOD;
            return cur;
        }
    }
    
    ll modInv(ll a) {
        return modExp(a, MOD - 2);
    }
    
    ll modDiv(ll a, ll b) {
        return modMul(a, modInv(b));
    }
}

using namespace Modop;

ll X, Y;
ll fac[MX];

void pre() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MX; i++) {
        fac[i] = modMul(i, fac[i - 1]);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    pre();
	cin >> X >> Y;
	if ((X + Y) % 3) {
		cout << "0";
		return 0;
	} else {
		ll rightMoves = (X - (Y - X)) / 3;
		ll upMoves = X - (2 * rightMoves);
        if (rightMoves < 0 || upMoves < 0) {
            cout << 0;
            return 0;
        }
		ll totalMoves = rightMoves + upMoves;		
		
        ll ans = fac[totalMoves];
        ans = modDiv(ans, fac[rightMoves]);
        ans = modDiv(ans, fac[totalMoves - rightMoves]);
        cout << ans;
	}
	
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result */
