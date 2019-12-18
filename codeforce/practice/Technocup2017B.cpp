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

bool is(char c){
    if(c>='0'&&c<='9')return 1;
    return c=='.';
}

int main() {
    str receipt;
    getline(cin, receipt);
    stringstream ss;
    ll ans = 0;

    F0R(i, sz(receipt))
    {
        if (is(receipt[i]))
        {
            ll v = 0;
            int dot = -1;
            while(is(receipt[i]))
            {
                if (receipt[i] != '.') v = v * 10 + receipt[i] - '0';
                else dot = i;
                ++i;
            }

            if (i - dot == 4 || dot == -1) v *= 100;
            ans += v;
            --i;
        }
    }
     
    if (ans < 100)
    {
        printf("0.%02d\n", ans);
        return 0;
    }

    vi digits;
    while(ans)
    {
        digits.pb(ans % 10);
        ans /= 10;
    }

    reverse(all(digits));
    F0R(i, sz(digits) - 2)
    {
        cout << digits[i];
        if ((sz(digits) - i) % 3 == 0 && i != sz(digits) - 3) cout << ".";
    }
    
    if (digits.back() || digits[sz(digits) - 2]) cout << "." << digits[sz(digits) - 2] << digits.back();
    else cout << "";

    // Some reverse thing to get the . in
    // Print ans differently if it's a whole number with no decimals or force precision
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
