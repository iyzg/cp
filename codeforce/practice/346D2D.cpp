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
    /*
     * plan
     * There are 4 cases where it's dangerous because of the assumption you start at SW:
     * Right -> UP
     * Up -> Left
     * Left -> Down
     * Down -> Right
     * All of these only work because to return to your start, these must be dangerous
     */
    int n; cin >> n;
    // Figure out the last direction you were headed
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    char last_dir;
    if (x2 > x1) last_dir = 'R';
    else if (x2 < x1) last_dir = 'L';
    else if (y2 > y1) last_dir = 'U';
    else last_dir = 'D';
    x1 = x2;
    y1 = y2;
    
    int ans = 0;
    F0R(i, n - 1)
    {
        cin >> x2 >> y2;
        if (x2 > x1) 
        {
            if (last_dir == 'D') ans++;
            last_dir = 'R';
        } else if (x2 < x1) {
            if (last_dir == 'U') ans++;
            last_dir = 'L';
        } else if (y2 > y1) {
            if (last_dir == 'R') ans++;
            last_dir = 'U';
        } else {
            if (last_dir == 'L') ans++;
            last_dir = 'D';
        }
                  
        x1 = x2;
        y1 = y2;
    }
    cout << ans;
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
