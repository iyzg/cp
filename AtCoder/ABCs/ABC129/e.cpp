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
const ll MOD = 1e9 + 7;
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

string L;
int N;
ll ans = 3;
ll saved[MX] { 1, 2 };

void solve() {
    cin >> L;
    N = L.size();
    int ones = 0;
    // This calcs for how many pairs share no bit if the leftmost bit is i away
    for (int i = 2; i < N; i++) {
		saved[i] = modMul(saved[i - 1], 3);
		ans = modAdd(ans, saved[i]);
		if (L[N - i] == '1') ones++;
	}
	
	if (!ones) {
		ans = modAdd(ans, modMul(saved[N - 1], 3));
		for (int j = 1; j < N; j++) {
			if (L[j] == '0') ans = modSub(ans, modMul(saved[j], 2));
	    }
	} else {
		for (int j = 1; j < N; j++) {
			if (L[j] == '1') {
				ans = modAdd(ans, modMul(saved[N - j], 3));
				break;
			}
		}
	}
	
	// for (int j = 1; j < N; j++) {
		// if (L[j] == '0') ans = modSub(ans, modMul(saved[j], 2));
	// }
	// cout << "\n";
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
