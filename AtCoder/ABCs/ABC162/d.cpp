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

int N;
str S;
// R, G, B
int a[3][4000];
ll ans;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    
    F0R(i, N) {
        if (S[i] == 'R') a[0][i]++;
        else if (S[i] == 'G') a[1][i]++;
        else a[2][i]++;
        if (i > 0) {
            F0R(j, 3) a[j][i] += a[j][i - 1];
        }
    }
    
    F0R(i, N) {
        FOR(j, i + 1, N) {
            char fC = S[i], sC = S[j];
            if (sC < fC) swap(fC, sC);
            if (fC == sC) continue;
            if (fC == 'B' && sC == 'G') {
                ans += a[0][N - 1] - a[0][j];
                int diff = j - i;
                if (j + diff < N && S[j + diff] == 'R') ans--;
            } else if (fC == 'B' && sC == 'R') {
                ans += a[1][N - 1] - a[1][j];
                int diff = j - i;
                if (j + diff < N && S[j + diff] == 'G') ans--;
            } else {
                ans += a[2][N - 1] - a[2][j];
                int diff = j - i;
                if (j + diff < N && S[j + diff] == 'B') ans--;
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
