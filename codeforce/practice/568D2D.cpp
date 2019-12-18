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

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        // cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;

vpl a;
ll n, in, d = -1, ri = -1;
bool valid = true;
    
vector<ll> genset(ll start, ll times, ll increment)
{
    vl res;
    F0R(i, n)
    {
        res.pb(start + (i * increment));
    }

    return res;
}

int main() {
    setIO();
    cin >> n;
    F0R(i, n)
    {
        cin >> in;
        a.pb(mp(in, i));
    }
    
    sort(all(a));
    
    // Remove first
    vl b = genset(a[1].f, n - 1, a[2].f - a[1].f);
    FOR(i, 1, n)
    {
        if (a[i].f != b[i - 1]) valid = false;
    }
    if (valid)
    {
        cout << 1;
        return 0;
    }

    // Remove second
    valid = true;
    b = genset(a[0].f, n - 1, a[2].f - a[0].f);
    F0R(i, n)
    {
        if (i == 0)
        {
            if (a[0].f != b[0]) valid = false;
        } else if (i == 1) {
            continue;
        } else {
            if (a[i].f != b[i - 1]) valid = false;
        }
    }
    if (valid)
    {
        cout << 2;
        return 0;
    }

    d = a[1].f - a[0].f;
    FOR(i, 1, n)
    {
        if (a[i].f - a[i - 1].f != d)
        {
            if (ri == -1)
            {
                ri = a[i].s;
                a.erase(a.begin() + i);
                --i;
                --n;
            } else {
                cout << -1;
                return 0;
            }
        }
    }

    if (ri == -1) cout << 1;
    else cout << ri + 1;

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
