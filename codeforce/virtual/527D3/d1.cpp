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
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    bitset<100000> wall;
    ll in;
    vi ss;
    vpi gss;
    F0R(i, n)
    {
        cin >> in;
        if (in % 2 == 1)
            wall[i] = 1;
        if (i == 0)
        {
            ss.pb(i);
        } else if (wall[i] != wall[i - 1])
        {
            if ((i - ss[sz(ss) - 1]) % 2 == 0)
            {
                gss.pb(mp(ss[sz(ss) - 1], i - 1));
            }
            ss.pb(i);
        }
    }
    
    F0R(i, sz(gss))
    {
        int ls = gss[i].f;
        int rs = gss[i].s;

        while (ls > 0 && rs < n - 1 && wall[ls] == wall[rs])
        {
            if (wall[ls - 1] == wall[rs + 1])
            {
                wall[ls - 1] = wall[ls];
                wall[rs + 1] = wall[rs];
                ls--;
                rs++;
            } else {
                break;
            }
        }
    }

    int odd_sequences = 0;
    for(int i = 0; i < n; i++)
    {
        int rs = i + 1;
        while (wall[rs] == wall[i] && rs < n)
            rs++;
        if ((rs - i) % 2 == 1)
            odd_sequences++;
        if (odd_sequences > 1)
        {
            cout << "NO";
            return 0;
        }
        i = rs - 1;
    }

    cout << "YES";

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
