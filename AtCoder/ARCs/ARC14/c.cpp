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
string S;
// R, G, B
set<int> nxt[3];
char letters[3] = {'R', 'G', 'B'};
deque<char> cur;

void solve() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
		if (S[i] == 'R') nxt[0].insert(i);
		else if (S[i] == 'G') nxt[1].insert(i);
		else nxt[2].insert(i);
	}
	
	for (int i = 0; i < N; i++) {
		int cn;
		for (int j = 0; j < 3; j++) {
			if (S[i] == letters[j]) cn = j;
		}
		nxt[cn].erase(nxt[cn].begin());
		if (!cur.size()) cur.push_back(S[i]);
		else if (cur.size() == 1) {
			if (S[i] == cur.front()) {
				cur.pop_front();
			} else {
				cur.push_back(S[i]);
			}
		} else {
			char a = cur.front(), b = cur.back();
			if (S[i] == a) cur.pop_front();
			else if (S[i] == b) cur.pop_back();
			else {
				int ai, bi;
				for (int j = 0; j < 3; j++) {
					if (a == letters[j]) ai = j;
					if (b == letters[j]) bi = j;
				}
				if (nxt[ai].size() && nxt[bi].size()) {
					if (*nxt[ai].begin() < *nxt[bi].begin()) {
						cur.push_back(S[i]);
					} else cur.push_front(S[i]);
				} else if (nxt[ai].size()) {
					cur.push_back(S[i]);
				} else {
					cur.push_front(S[i]);
				}
			}
		}
		// for (auto& j : cur) cout << j;
		// cout << "\n";
	}
	
	cout << cur.size() << "\n";
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
