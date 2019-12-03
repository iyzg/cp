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
    ll a[n], left[n] = { 0 }, right[n] = { 0 };
    bitset<20000000> exists;
    bitset<20000000> more_than_one;
    exists.reset();
    more_than_one.reset();
    int max = 0;
    F0R(i, n) 
    {
        cin >> a[i];
        if (exists[a[i]] == 0)
            exists[a[i]] = 1;
        else if (more_than_one[a[i]] == 0)
            more_than_one[a[i]] = 1;
        if (a[i] > max)
            max = a[i];
    }
    
    FOR(i, 1, n)
    {
        left[i] = a[i - 1] + left[i - 1];
    }

    R0F(i, n - 1)
    {
        right[i] = a[i + 1] + right[i + 1];
    }

    int ans = 0;
    vi nice;
    F0R(i, n)
    {
        ll sum = right[i] + left[i];
        if (sum % 2 == 0 && sum / 2 <= max)
        {
            if (exists[sum / 2])
            {
                if (a[i] == sum / 2)
                {
                    if (more_than_one[sum / 2] == 1)
                    {
                        ans++;
                        nice.pb(i + 1);
                    }
                } else {
                    ans++;
                    nice.pb(i + 1);
                }
            }
        }
    }
    
    if (ans == 0)
        cout << "0";
    else 
    {
        cout << ans << "\n";
        F0R(i, sz(nice))
        {
            cout << nice[i] << " ";
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
