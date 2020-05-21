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

string S;

vector<int> z_function(string s) {
	int n = (int)s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i  + 1, z[i - l]);
		while (i + z[i] < n && S[z[i]] == S[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

void solve() {
    cin >> S;
    int N = S.size();
    vector<int> z = z_function(S);
    int ans = 0;
    set<int> valid;
    for (int i = N - 1; i >= 1; --i) {
		if (z[i] == N - i) valid.insert(z[i]);
	}
	if (!valid.size()) {
		cout << "Just a legend";
		return;
	}
	// for (auto& i : valid) cout << i << " ";
	// cout << "\n";
    for (int i = 0; i < N; i++) {
		if (!z[i]) continue;
		// Prefix
		// cout << S.substr(0, z[i]) << " " << S.substr(N - z[i], z[i]) << "\n";
		// cout << z[i] << "\n";
		auto it = valid.upper_bound(z[i] - 1);;
		if (i + z[i] == N) it = valid.upper_bound(z[i] - 1);
		else it = valid.upper_bound(z[i]);
		if (it == valid.begin()) continue;
		--it;
		// cout << *it << "\n";
		chmax(ans, *it);
	}
	!ans ? cout << "Just a legend" : cout << S.substr(0, ans);
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
