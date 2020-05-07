#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000001;

int N, M;
ll sum;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vi a(M), shift(M);
    F0R(i, M) {
        cin >> a[i];
        sum += a[i];
        shift[i] = 0;
    }
    reverse(all(a));
    // Can't fill all the positions or not enough free space
    if (sum < N || N - a[0] < M - 1) {
        cout << -1;
        return 0;
    }
    
    vi ans;
    ans.pb(1);
    int pos = 1 + a[0];
    FOR(i, 1, M) {
        // cout << "peos: " << pos << "\n";
        int segStart = max(1, pos - a[i] + 1);
        ans.pb(segStart);
        pos = segStart + a[i];
    }
    
    // too much
    if (pos > N + 1) {
        cout << -1;
        return 0;
    }
    
    // shifts
    if (pos < N + 1) {
        int shiftsNeeded = N + 1 - pos;
        FOR(i, 1, M) {
            int toShift = min(max(0, (ans[i - 1] + a[i - 1] - ans[i])), shiftsNeeded);
            shift[i] = toShift;
            shiftsNeeded -= toShift;
        }
    }
    
    // trav(i, ans) cout << i << " ";
    // cout << "\n";
    ll shifts = 0;
    F0R(i, M) {
        shifts += shift[i];
        ans[i] += shifts;
    }
    // trav(i, shift) cout << i << " ";
    // cout << "\n";
    reverse(all(ans));
    trav(i, ans) cout << i << " ";
    // reverse(all(ans));
    // Account for shifts
    // int shiftsAcquired = 0;
    // F0R(i, M) {
        // shiftsAcquired += shift[i];
        // cout << shiftsAcquired << " ";
        // cout << ans[i] + shiftsAcquired << " ";
        // cout << "\n";
    // }
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
