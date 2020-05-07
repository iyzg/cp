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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MX = 1000001;

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

int N;
ll ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    // int total[5] = {0};
    // FOR(i, 1, (1 << 2)) {
        // int cnt = 0;
        // F0R(j, 2) {
            // if ((1 << j) & i) total[j] += ++cnt;
        // }
    // }
    // trav(i, total) cout << i << " ";
    cin >> N;
    vl a(N); 
    F0R(i, N) {
        cin >> a[i];
    }
    sort(all(a), greater<ll>());
    vl mul;    
    if (N == 1) mul.pb(1);
    else mul.pb(modDiv(modExp(2, N), 2));
    ll toAdd = modDiv(mul[0], 2);
    F0R(i, N) {
        // ll toAdd = 0;
        // F0R(j, sz(mul)) {
            // toAdd += modMul(j + 1, modMul(mul[j], a[i]));
        // }
        
        // cout << "ToAdd: " << toAdd << "\n";
        // ans = modAdd(ans, toAdd);
        ans = modAdd(ans, mul[0] * a[i]);

        // Ignore
        // trav(j, mul) cout << j << " ";
        // cout << ans << "\n";
        // R0F(j, sz(mul) - 1) {
            // mul[j + 1] = (mul[j] + mul[j + 1]) / 2;
        // }
        // mul[0] /= 2;
        // mul.pb(mul[0]);
        mul[0] = modAdd(mul[0], toAdd);
    }
 
    ans = modMul(ans, modExp(2, N));
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
