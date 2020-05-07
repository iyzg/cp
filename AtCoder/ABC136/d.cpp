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

str S;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> S;
    int a[sz(S)], ans[sz(S)];
    F0R(i, sz(S)) {
        a[i] = ans[i] = 0;
    }
    
    FOR(i, 1, sz(S)) {
        if (S[i] == 'L' && S[i - 1] == 'R') a[i] = i;
        else if (S[i] == 'L')a[i] = a[i - 1];
    }
    
    R0F(i, sz(S) - 1) {
        if (S[i] == 'R' && S[i + 1] == 'L') a[i] = i;
        else if (S[i] == 'R') a[i] = a[i + 1];
    }
        
    F0R(i, sz(S)) {
        if (S[i] == 'R') {
            int dist = a[i] - i;
            if (dist % 2) ans[a[i] + 1]++;
            else ans[a[i]]++;
        } else {
            int dist = i - a[i];
            if (dist % 2) ans[a[i] - 1]++;
            else ans[a[i]]++;
        }
    }
    
    trav(i, ans) cout << i << " ";
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
