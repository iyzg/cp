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
const int MX = 500005;

int N, Q;
char S[MX];
int t[4*MX];

void build(char a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = pow(2, a[tl] - 97);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = (t[v*2] | t[v*2+1]);
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, min(r, tm))
            | sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, char new_val) {
    if (tl == tr) {
        t[v] = pow(2, new_val - 97);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] | t[v*2+1]);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    F0R(i, N) cin >> S[i];
    build(S, 1, 0, N - 1);    
    // F0R(i, 4*N) cout << t[i] << " ";
    // cout << "\n";
    cin >> Q;
    while(Q--) {
        int type; cin >> type;
        if (type == 1) {
            int index; char c;
            cin >> index >> c; index--;
            update(1 , 0, N - 1, index, c);
            // F0R(i, 4*N) cout << t[i] << " ";
        } else {
            int a, b; cin >> a >> b;
            a--; b--;
            ll totalCnt = sum(1, 0, N - 1, a, b);
            // cout << totalCnt << "\n";
            int sum = 0;
            F0R(bits, 26) if ((1 << bits) & totalCnt) sum++;
            cout << sum << "\n";
        }
    }
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
