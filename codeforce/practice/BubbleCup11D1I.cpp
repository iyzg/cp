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
 
int main() {
    setIO();
    int n; cin >> n;
    map<int, int> letterCount;
    ll ans = 0;
 
    str in; getline(cin, in);
    F0R(i, n)
    {
        getline(cin, in);
        int letters[26] = { 0 };
        F0R(j, sz(in)) letters[in[j] - 97]++;
 
        F0R(j, 26) letters[j] %= 2;
        int key = 0;
        
        F0R(j, 26) 
        {
            if (letters[j]) key += (pow(2, j) + 0.5);
        }

        ans += letterCount[key];
        letterCount[key]++;
    }

    trav(i, letterCount)
    {
        F0R(j, 26)
        {
            if (letterCount.find(i.first + (pow(2, j) + 0.5)) != letterCount.end() && !((i.first & (1 << j))))
                ans += i.second * letterCount[(i.first + (pow(2, j) + 0.5))];
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
