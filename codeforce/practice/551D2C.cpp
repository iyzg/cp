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

int n;
int lc = 0, rc = 0;
str line, ans;

int main() {
    setIO();
    cin >> n; 
    if (n % 2 == 1)
    {
        cout << ":(";
        return 0;
    }

    getline(cin, line);
    getline(cin, line);

    F0R(i, n)
    {
        if (line[i] == '(') ++lc;
        else if (line[i] == ')') ++rc;
    }

    F0R(i, n)
    {
        if (line[i] == '?')
        {
            if (lc < n / 2)
            {
                ++lc;
                line[i] = '(';
            } else {
                ++rc;
                line[i] = ')';
            }
        }
    }

    // Check validity
    bool valid = true;
    int nlc = 0, nrc = 0;
    F0R(i, n)
    {
        line[i] == '(' ? ++nlc : ++nrc;
        if (i < n - 1 && nlc == nrc) valid = false;
        else if (nrc > nlc) valid = false;
    }

    if (nlc != nrc) valid = false;

    valid ? cout << line : cout << ":(";
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
