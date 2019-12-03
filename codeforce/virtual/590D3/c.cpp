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
    int Q; cin >> Q;
    F0R(q, Q)
    {
        int n; cin >> n;
        str top, bot;
        getline(cin, top);
        getline(cin, top);
        getline(cin, bot);

        ll r = 1, c = 0;
        char dir = 'l';
        while (!(r == 2 && c == n))
        {
            if (r == 1)
            {
                if (top[c] == '1' || top[c] == '2')
                {
                    if (dir == 'l')
                    {
                        c++;
                    }
                    else
                        break;
                } else {
                    if (dir == 'l')
                    {
                        r++;
                        dir = 't';
                    } else if (dir == 'b') {
                        dir = 'l';
                        c++;
                    } else {
                        break;
                    }
                }

            } else {
                if (bot[c] == '1' || bot[c] == '2')
                {
                    if (dir == 'l')
                        c++;
                    else
                        break;
                } else {
                    if (dir == 'l')
                    {
                        r--;
                        dir = 'b';
                    } else if (dir == 't') {
                        dir = 'l';
                        c++;
                    } else {
                        break;
                    }
                }

            }
        }

        if (r == 2 && c == n && dir == 'l')
        {
            // cout << r << " " << c << " " << dir << "\n";
            cout << "YES\n";
        }
        else
        {
            // cout << r << " " << c << " " << dir << "\n";
           cout << "NO\n";
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
