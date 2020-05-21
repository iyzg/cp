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

int N;
map<int, int> cnt;

void solve() {
    cin >> N; vector<int> a(N);
	for (auto& i : a) {
		cin >> i;
		cnt[i]++;
	}
	
	vector<int> cnts;
	for (auto& i : cnt) {
		cnts.push_back(i.second);
	}
	sort(cnts.begin(), cnts.end());
	
	vector<int> fin;
	for (int len = 1; len <= (int)cnts.size(); len++) {
		int sub[N] = { 0 };
		int ans = 0;
		for (int rb = len - 1; rb < (int)cnts.size(); rb++) {
			ans += cnts[rb - (len - 1)];
			int li = upper_bound(cnts.begin(), cnts.end(), cnts[rb - (len - 1)]) - cnts.begin();
			--li;
			if (li < rb) rb += li - (rb - (len - 1));
			cout << len << " " << ans << " " << rb << "\n";
		}
		fin.push_back(ans);
	}
	for (auto& i : fin) cout << i << "\n";
	for (int i = 0; i < N - (int)fin.size(); i++) cout << "0\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll testCases = 1; // cin >> testCases;
    while (testCases--) solve();
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
