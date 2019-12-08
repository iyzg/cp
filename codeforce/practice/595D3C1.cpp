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
    ll max[40] = { 0 };
    F0R(i, 40)
    {
        if (i == 0) max[i] = 1;
        else max[i] = max[i - 1] + (ll)(pow((ld)3, (ld)i) + 0.5);
    }

    int Q; cin >> Q;
    F0R(q, Q)
    {
        ll n, limit = 40, ans = 0; cin >> n;
        ll left = n;
        while (ans < n)
        {
            F0R(i, limit)
            {
                if (max[i] >= left)
                {
                    ans += (ll)(pow((ld)3, (ld)i) + 0.5);
                    left -= (ll)(pow((ld)3, (ld)i) + 0.5);
                    break;
                }
            }
        }

        cout << ans << "\n";
        /*
         * plan
         * loop through max and settle on the one that can go over
         * loop through again and find max that is smallest and take that one
         */
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
