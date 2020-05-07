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
const ll MX = 1000001;

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

ll N, K, ans = 1;

void solve() {
    cin >> N >> K;
    ll res = 1, other = 1;
    // precalc other spots
    for (int i = 1; i < N; i++) {
        other = modMul(other, i);
        if (i < N - 1) other = modMul(other, modInv(i));
        
    }
    
    // i is the number of empty rooms
    for (int i = 1; i <= min(N - 1, K); i++) {
        // res is how many ways there are to choose i empty rooms
        res = modMul(res, N - i + 1);
        res = modMul(res, modInv(i));
        // Each moved person can choose one of the places to stay
        
        // cout << i << " " << res << " " << other << "\n";
        ans = modAdd(ans, modMul(res, other));
        
        // Update number of places to move for next 
        other = modMul(other, modInv(i + 1));
        other = modMul(other, N - i - 1);
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
