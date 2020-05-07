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

int N, M, Q;
int a[50][4];

void solve() {
    cin >> N >> M >> Q;
    // cout << "Q: " << Q << "\n";
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
        a[i][0]--; a[i][1]--;
    }
    
    string perm = string(N, 'o') + string(M - 1, 'x');
    int ans = 0;
    do {
        vector<int> arr(N);
        int cur = 0, pos = 0;
        for (char c : perm) {
            if (c == 'o'){
                arr[pos++] = cur;
            } else {
                cur++;
            }
        }
        int score = 0;
        for (int i = 0; i < Q; i++) {
            if (arr[a[i][1]] - arr[a[i][0]] == a[i][2]) {
                score += a[i][3];
            }
        }
        
        chmax(ans, score); 
    } while (next_permutation(perm.begin(), perm.end()));
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
