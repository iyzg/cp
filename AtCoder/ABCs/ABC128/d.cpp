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

int N, K, ans;
vector<int> a;

void solve() {
    cin >> N >> K;
    a.resize(N);
    for (auto& i : a) cin >> i;
    
    
    for (int leftTake = 0; leftTake <= min(N, K); leftTake++) {
		int tmp = 0;
		multiset<int> lq, rq;
		for (int i = 0; i < leftTake; i++) {
			lq.insert(a[i]);
			tmp += a[i];
		}
		for (int rightTake = 0; rightTake + leftTake <= min(N, K); rightTake++) {
			int rtmp = tmp;
			for (int i = 1; i <= rightTake; i++) {
				rq.insert(a[N - i]);
				rtmp += a[N - i];
			}
			
			auto lp = lq.begin(), rp = rq.begin();
			for (int i = 0; i < K - leftTake - rightTake; i++) {
				bool lv = (lp != lq.end() && *lp < 0), rv = (rp !=  rq.end() && *rp < 0);
				if (lv && rv) {
					if (*lp < *rp) {
						rtmp -= *lp;
						lp++;
					} else {
						rtmp -= *rp;
						rp++;
					}
				} else if (lv) {
					rtmp -= *lp;
					lp++;
				} else if (rv) {
					rtmp -= *rp;
					rp++;
				} else break;
			}
			
			// cout << leftTake << " " << rightTake << " " << rtmp << "\n";
			chmax(ans, rtmp);
			rq.clear();
		}
		lq.clear();
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
