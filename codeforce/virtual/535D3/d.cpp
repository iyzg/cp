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
    str garland;
    getline(cin, garland);
    getline(cin, garland);

    int cnt = 0;
    if (n == 1) 
    {
        cout << cnt << "\n";
        cout << garland;
        return 0;
    } else if (n == 2)
    {
        if (garland[0] == garland[1])
        {
            if (garland[0] == 'R')
                garland[1] = 'B';
            else 
                garland[1] = 'R';
            cnt++;
        }
        cout << cnt << "\n";
        cout << garland;
        return 0;
    }

    // Triple Fixs
    FOR(i, 1, n - 1)
    {
        if (garland[i] == garland[i - 1] && garland[i] == garland[i + 1])
        {
            cnt++;
            bitset<3> RGB;
            RGB.set();
            if (garland[i - 1] == 'R' && garland[i + 1] == 'R')
                RGB[0] = 0;
            else if (garland[i - 1] == 'G' && garland[i + 1] == 'G')
                RGB[1] = 0;
            else if (garland[i - 1] == 'B' && garland[i + 1] == 'B')
                RGB[2] = 0;
            
            if (RGB[0])
                garland[i] = 'R';
            else if (RGB[1])
                garland[i] = 'G';
            else if (RGB[2])
                garland[i] = 'B';
            i++;
        }
    }

    FOR(i, 1, n - 1)
    {
        if (garland[i] == garland[i - 1] || garland[i] == garland[i + 1])
        {
            cnt++;
            bitset<3> RGB;
            RGB.set();
            if (garland[i - 1] == 'R' || garland[i + 1] == 'R')
                RGB[0] = 0;
            if (garland[i - 1] == 'G' || garland[i + 1] == 'G')
                RGB[1] = 0;
            if (garland[i - 1] == 'B' || garland[i + 1] == 'B')
                RGB[2] = 0;
            
            if (RGB[0])
                garland[i] = 'R';
            else if (RGB[1])
                garland[i] = 'G';
            else if (RGB[2])
                garland[i] = 'B';
        }
    }

    cout << cnt << "\n";
    cout << garland;
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
