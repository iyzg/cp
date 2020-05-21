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
const ll MX = 200005;

ll N, K, C;
char days[MX];
int pos[MX];

void solve() {
    cin >> N >> K >> C;
    for (int i = 0; i < N; i++) cin >> days[i];
    for (int i = 0; i < N; i++) {
        pos[i] = (days[i] == 'o');
        
        if (i > C) pos[i] += pos[i - C - 1];
        if (i) chmax(pos[i], pos[i - 1]);
    }
    
    if (pos[N - 1] > K) return;
    
    // Go backwards and find the first one you couldn't do without
    // If it's the last one and the one before != N
    // Store the number the thing enables, if no other o has that then it's needed
    // Set, if 
    
    // for (int i = 0; i < N; i++) cout << pos[i] << "\n";
    set<int> found;
    vector<int> ans;
    for (int i = N - 1; i >= 0; i--) {
        if (days[i] == 'o' && !found.count(pos[i])) {
            if (i == 0) {
                ans.push_back(i + 1);
            } else if (pos[i] > pos[i - 1]) {
                ans.push_back(i + 1);
            }
            found.insert(pos[i]);
            i -= C;
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (auto& i : ans) cout << i << "\n";
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
