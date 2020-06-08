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
const ll MX = 100005;

ll N, M, V, P;
map<ll, ll> cnt;
ll ans;

bitset<MX> used;

void solve() {
    cin >> N >> M >> V >> P;
    vector<int> a(N);
    for (auto& i : a) {
		cin >> i;
		cnt[i]++;
	}
    
    vector<l_l> cnts;
    for (auto& i : cnt) {
		cnts.push_back({i.first, i.second});
	}
	
	ll cur = 0;
	for (int i = 0; i < (int)cnts.size(); i++) {
		if (i == (int)cnts.size() - 1) {
			ans += cnts[i].second;
			break;
		}
		
		cur += cnts[i].second;
		int ahead = V - cur + 1;
		if (i < (int)cnts.size() - 1 && cnts[i + 1].second <= ahead) {
			continue;
		}
		int stragglers = ahead - cnts[i + 1].second;
		
		used.reset();
		l_l finp[2];
		ll tmp = cnts[j + 1].second;
		for (j = i + 1; j < (int)cnts.size(); j++) {
			// Takes cnts[j].first - cnts[i].first judges to raise to the next level
			if (j == (int)cnts.size() - 1) {
				
			} else {
				if (V) {
					
				}
			}
		}
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
