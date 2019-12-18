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
    int n; cin >> n;
    str a, b;
    int count[26] = { 0 };
    getline(cin, a);
    getline(cin, a);
    getline(cin, b);
    
    F0R(i, n)
    {
        count[a[i] - 97]++;
        count[b[i] - 97]--;
    }

    F0R(i, 26)
    {
        if (count[i] != 0)
        {
            cout << -1;
            return 0;
        }
    }
    if (a == b)
    {
        cout << 0;
        return 0;
    }

    int moves = 0;
    vi movelist;
    R0F(i, n)
    {
        if (a[i] != b[i])
        {
            int index = -1;
            R0F(j, i)
            {
                if (a[j] == b[i])
                {
                    index = j;
                    break;
                }
            }

            FOR(j, index, i)
            {
                char temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                movelist.pb(j + 1);
                ++moves;
            }
        }
    }
    

    cout << moves << "\n";
    F0R(i, sz(movelist))
    {
        cout << movelist[i] << " ";
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
