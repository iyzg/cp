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

int K, N;

void solve() {
    cin >> N >> K;
    vector<ll> a(N), b(N), ans;
    set<int> in;
    for (int i = 0; i < N; i++) {
        cin >> a[i];   
        b[i] = a[i];
        in.insert(a[i]);
    } 
    
    set<int> begin;
    for (int i = 0; i < K; i++) {
        if (begin.find(a[i]) == begin.end()) begin.insert(a[i]);
        else break;
    }
    
    if ((int)in.size() > K) {
        cout << "-1\n";
        return;
    }
    
    for (auto i : in) {
        if (begin.find(i) == begin.end()) a.insert(a.begin(), i);
    }
        
    vector<ll> cycle;
    int cycleindex = 0;
    for (int i = 0; i < K; i++) {
        ans.push_back(a[i]);
        cycle.push_back(a[i]);
    }
    
    for (int i = K; i < (int)a.size(); i++) {
        while (a[i] != cycle[cycleindex % (int)cycle.size()]) {
            ans.push_back(cycle[cycleindex % (int)cycle.size()]);
            cycleindex++;
        }
        ans.push_back(a[i]);
        cycleindex++;
    }
    
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T; cin >> T;
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
