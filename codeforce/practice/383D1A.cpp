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

int a[100];
bool v[100];
bool e[100];
int visit(int last, int curr)
{
    v[curr] = true;
    if (!v[a[curr] - 1])
    {
        return 1 + visit(curr, a[curr] - 1);
    } else if (a[curr] - 1 == curr && curr != last) {
        return 101;
    } else {
        return 1;
    }
}


int main() {
    int n; cin >> n;
    
    F0R(i, n) 
    {
        cin >> a[i];
        e[a[i] - 1] = true;
    }

    F0R(i, n)
    {
        if (!e[i])
        {
            cout << -1;
            return 0;
        }
    }

    vi lengths;
    F0R(i, n)
    {
        if (!v[i])
        {
            int curr = visit(-1, i);
            if (curr > 101)
            {
                cout << -1;
                return 0;
            } else {
                if (curr == 101) curr = 1;
                if (curr % 2 == 0) curr /= 2;
                lengths.pb(curr);
            }
        }
    }

    if (sz(lengths) == 1) cout << lengths[0];
    else {
        int ans = lengths[0];
        FOR(i, 1, sz(lengths))
        {
            ans = (lengths[i] * ans) / __gcd(lengths[i], ans);
        }
        cout << ans;
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
