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
    
    ll inv(ll base) {
        int g = MOD, r = base, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
        return x < 0 ? x+MOD : x;
    }
    
    ll modDiv(ll a, ll b) {
        return modMul(a, inv(b));
    }
}

using namespace Modop;

int N;
ll sum;
map<ll, ll> factorCnt;
vl primes;
bitset<100000> isPrime;

void sieve() {
    isPrime.set();
    FOR(i, 2, 100000) {
        if (isPrime[i]) {
            primes.pb(i);
            for(int j = i * 2; j < 100000; j += i) isPrime[j] = 0;
        }
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    sieve();
    
    cin >> N;
    vl a(N); 
    F0R(i, N) {
        cin >> a[i];
        ll v = a[i];
        
        trav(prime, primes) {
            ll cnt = 0;
            while (v % prime == 0) {
                v /= prime;
                cnt++;
            }
            if (cnt > 0) factorCnt[prime] = max(factorCnt[prime], cnt);
        }
        
        // In case it's prime
        if (v > 1) factorCnt[v] = 1;
    }
    
    ll LCM = 1;
    trav(i, factorCnt) {
        LCM *= modExp(i.f, i.s);
        LCM %= MOD;
    }
    // cout << LCM << "\n";
    
    ll ans = 0;
    F0R(i, N) {
        ans += inv(a[i]); ans %= MOD;
    }
    // cout << ans << "\n";
    ans *= LCM; ans %= MOD;
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
