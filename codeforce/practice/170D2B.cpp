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
    str a[n];
    bitset<26> alpha;
    getline(cin, a[0]);
    F0R(i, n)
    {
        getline(cin, a[i]);
        F0R(j, sz(a[i]))
        {
            alpha[a[i][j] - 97] = 1;
        }
    }

    F0R(i, 26)
    {
        if (!alpha[i])
        {
            cout << (char)(i + 97);
            return 0;
        }
    }
    
    char curr = 'a';
    while(curr != 'z')
    {
        alpha.reset();
        F0R(i, n)
        {
            F0R(j, sz(a[i]))
            {
                if (a[i][j] == curr && j < sz(a[i]) - 1) alpha[a[i][j + 1] - 97] = 1;
            }
        }

        F0R(i, 26)
        {
            if (!alpha[i])
            {
                cout << curr << (char)(i + 97);
                return 0;
            }
        }
        ++curr;
    }

    
    // Second check for two letter combos

    return 0;
    // You should actually read the stuff at the bottom
    // Note: max length has to be 2 letters since it's impossible to rule out every 2 letter combination because of low constraints
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
