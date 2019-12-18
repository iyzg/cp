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

const ll MOD = 1000000007;

int main() {
    int n; cin >> n;
    str brackets; getline(cin, brackets);
    getline(cin, brackets);
    int left = 0, right = 0;
    F0R(i, sz(brackets))
    {
        if (brackets[i] == '(') ++left;
        else
        {
            if (left > 0) --left;
            else ++right;
        }
    }
    
    if (left + right > 2 * n - sz(brackets) || ((2 * n - sz(brackets)) % 2 == 1 && (left + right) % 2 == 0))
    {
        cout << 0;
        return 0;
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
