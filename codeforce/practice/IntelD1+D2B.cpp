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


int main() {
    int n, m; cin >> n >> m;
    /*
     * plan
     * If more than 4 numbers are out of order, than its impossible.
     * If more than 2 numbers are out of order, just brute force since constraints so small. Just check what happens in each different of the 3 different swaps 
     * (a & b, a & c, b & c). CHecking each time if each row only has 1 swap after that.
     */
    int a[n][m];
    pair<int, vi> rows[n];
    int needed = false;
    F0R(i, n)
    {
        F0R(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] != j + 1)
                rows[i].s.pb(j);
        }
        rows[i].f = max(0, sz(rows[i].s) - 1);
        if (rows[i].f > 1) needed = true;
    }

    if (needed)
    {
        
    } else {
        cout << "YES";
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
