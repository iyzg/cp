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
    int T; cin >> T;
    F0R(t, T)
    {
        int n; cin >> n;
        str a[n];
        getline(cin, a[0]);
        int cn = 0;
        F0R(i, n)
        {
            getline(cin, a[i]);
        }
    
        F0R(i, n)
        {
            F0R(j, i)
            {
                if (a[i] == a[j])
                {
                    bool unique = false;
                    cn++;
                    while (!unique)
                    {
                        int start = a[i][0] - '0';
                        start = (start + 1) % 10;
                        a[i][0] = start + '0';
                        unique = true;
                        F0R(k, n)
                        {
                            if (a[k] == a[i] && k != i)
                            {
                                unique = false;
                                break;
                            }
                        }
                    }
                
                }
            }
        }


        cout << cn << "\n";
        F0R(i, n)
        {
            cout << a[i] << "\n";
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
