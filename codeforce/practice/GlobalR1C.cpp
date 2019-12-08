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
    int Q, num = 0; cin >> Q;
    vi maxs;
    int intervals[26];
    F0R(i, 26)
    {
        num += pow(2, i);
        intervals[i] = pow(2, i);
        maxs.pb(num);
    }
    F0R(q, Q)
    {
        int a; cin >> a;
        vi::iterator it = find(maxs.begin(), maxs.end(), a);
        if (it == maxs.end())
        {
            F0R(i, 26)
            {
                if (a < maxs[i])
                {
                    cout << maxs[i] << "\n";
                    break;
                }
            }
        } else {
            int limit = distance(maxs.begin(), it) + 1;
            int total = 0;
            F0R(i, limit)
            {
                total += intervals[i];
                cout << "Added " << intervals[i] << "\n";
            }
            cout << "Interval: " << total << "\n";
            total % 3 == 0 ? cout << total / 3 << "\n" : cout << "1\n";
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
