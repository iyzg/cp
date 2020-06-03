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
const ll MOD = 998244353;
const ll MX = 1000001;

int A, B, C, D, E, F;
bool dp[3005]; 
set<int> pos;

long double dens = -1;
ll tot = 0, sug = 0;

void solve() {
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100; B *= 100;
    
    // Precalc pos amount of sugar to add 
	dp[0] = true;
	pos.insert(0);
    for (int i = 0; i < 3005; i++) {
		if (i - C >= 0 && dp[i - C]) {
			dp[i] = true;
			pos.insert(i);
		} else if (i - D >= 0 && dp[i - D]) {
			dp[i] = true;
			pos.insert(i);
		}
	}
	
    for (int a = 0; a <= F / A; a++) {
		for (int b = 0; (b * B) + (a * A) <= F; b++) {
			int water = (b * B) + (a * A);
			// cout << a << " " << b << " " << water << "\n";
			int maxSugar = min(F - water, water / 100 * E);
			
			auto it = pos.lower_bound(maxSugar);
			if (it == pos.begin()) continue;
			if (it == pos.end() || *it != maxSugar) --it;
			// cout << *it << "\n";
			int sugar = *it;
			long double tmpD = ((long double)sugar / (long double)(water + sugar));
			// cout << sugar << " " << water << "\n";
			if (tmpD > dens) {
				dens = tmpD;
				tot = water + sugar;
				sug = sugar;
			}
		}
	}
	
	cout << tot << " " << sug;
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
