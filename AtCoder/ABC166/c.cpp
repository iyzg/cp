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

int N, M, A, B;
int height[MX];
vector<int> graph[MX];

int valid(int v) {
    if (graph[v].size() == 0) {
        return 1;
    }
    
    for (auto& u : graph[v]) {
        if (height[u] >= height[v]) return 0;
    }

    return 1;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> height[i];
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += valid(i);
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
