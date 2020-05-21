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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MX = 1000001;

str N;
ll K, ans; 

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    vi a(sz(N));
    F0R(i, sz(N)) a[i] = N[i] - '0';
    
    if (K == 1) {
        F0R(i, sz(N)) {
            if (i == 0) ans += a[i];
            else ans += 9;
        }
    } else if (K == 2) { 
        R0F(i, sz(a) - 1) {
            if (i != 0) {
                ans += (sz(a) - (i + 1)) * 9 * 9;
            } else {
                bool secondDigit = false;
                FOR(j, 1, sz(a)) {
                    if (secondDigit) ans += a[i] * 9;
                    else {
                        if (a[j]) {
                            secondDigit = true;
                            ans += a[j];
                            ans += (a[i] - 1) * 9;
                        }
                    }
                }
            }
        }
    } else {
        R0F(i, sz(a) - 2) {
            if (i != 0) {
                ll toRight = sz(a) - (i + 1);
                ll combos = toRight * (toRight - 1) / 2;
                ans += combos * 729;
            } else {
                bool second = false, third = false;
                FOR(j, 1, sz(a) - 1) {
                    if (!a[j] && !second) continue;

                    FOR(k, j + 1, sz(a)) {
                        if (!second) {
                            if (third) ans += a[i] * a[j] * 9;
                            else {
                                if (!a[k]) continue;
                                ans += a[i] * a[j] * a[k];
                                third = true;
                            }
                        } else {
                            ans += a[i] * 9 * 9;
                        }
                    }
                    second = true;
                }
            }
        }
    }
    
    cout << ans;
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
