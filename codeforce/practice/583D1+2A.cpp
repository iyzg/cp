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
    ll n; cin >> n;
    int d, e; cin >> d >> e;
    // Two cases, one with taking euro first and then taking dollar first and see which one is better
    e *= 5; // You have to buy at least 5 at a time
    bool ad = true, ae = true;
    if (d > n) ad = false;
    if (e > n) ae = false;
    if (!ad && !ae) 
    {
        cout << n;
    } else if (ad && !ae) {
        cout << n - ((n / d) * d);
    } else if (!ad && ae) {
        cout << n - ((n / e) * e);
    } else {
        if (n % d == 0 || n % e == 0) 
        {
            cout << 0;
        } else {
            ll opt = n;
            int dt = (n / d);
            int et = 0;
            while (dt > -1)
            {
                et = (n - (dt * d)) / e;
                opt = min(opt, n - (dt * d + et * e));
                dt--;
                // Add as many euro
                // Check if it's a new optimal
                // Remove a dollar
            }
            cout << opt;
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
