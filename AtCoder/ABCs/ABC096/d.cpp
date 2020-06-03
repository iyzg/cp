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
const ll MX = 55001;

int N;
vector<int> primes;
set<int> is;
bitset<MX> valid;

void sieve() {
	valid.set();
	for (int i = 2; i < MX; i++) {
		if (valid[i]) {
			primes.push_back(i);
			is.insert(i);
			for (int j = i + i; j < MX; j += i) valid[j] = false;
		}
	}
	
}

void solve() {
    sieve();
    cin >> N;
    vector<int> ans;
    for (int i = 0; i < (int)primes.size(); i++) {
		if ((int)ans.size() == N) break;
		if ((int)ans.size() < 2) {
			ans.push_back(primes[i]);
		} else {
			if (primes[i] % 10 == 3) {
				ans.push_back(primes[i]);
			}
		}
	}
	
	for (auto& i : ans) cout << i << " ";
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
