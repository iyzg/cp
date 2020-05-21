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
const ll MX = 300005;

int N, M, U, V;
set<int> swaps[MX];

void solve() {
    cin >> N >> M;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    int num = a[a.size() - 1];
    for (int i = 0; i < M; i++) {
		cin >> U >> V;
		swaps[U].insert(V);
	}
    
    for (int i = N - 2; i >= 0; --i) {
		int cur = i;
		while (cur < N - 1 && swaps[a[cur]].find(a[cur + 1]) != swaps[a[cur]].end()) {
			swap(a[cur], a[cur + 1]);
			if (a[cur] == num) break;
			cur++;
		}
	}
	for (int i = 0; i < N ; i++) {
		if (a[i] == num) {
			cout << N - 1 - i;
			return;
		}
	}
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
