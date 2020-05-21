#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll MX = 100005;

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

ll facs[MX], facInvs[MX];

void initFacs() {
	facs[0] = facInvs[0] = 1;
	for(int i = 1; i < MX; i++) {
		facs[i] = modMul(facs[i - 1], i);
		facInvs[i] = modInv(facs[i]);
	}
}

ll choose(ll a, ll b) {
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    ll cur = facs[a];
    cur = modMul(cur, facInvs[b]);
    cur = modMul(cur, facInvs[a-b]);
    return cur;
}

ll N, K;
ll ans;

void solve() {
    initFacs();
    cin >> N >> K;
	vector<ll> a(N); for(auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    // Summation of max
	for (int i = K - 1; i < N; ++i) {
		ll cnt = choose(i, K - 1);
		ll val = a[i] + MOD; val %= MOD;
		val *= cnt; val %= MOD;
		ans += val; ans %= MOD;
	}
	
	// Summation of min
	for (int i = 0; i < N - K + 1; i++) {
		ll cnt = choose(N - i - 1, K - 1);
		ll val = a[i] + MOD; val %= MOD;
		val *= cnt; val %= MOD;
		ans += MOD - val; ans %= MOD;
	}
	
	cout << ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
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
