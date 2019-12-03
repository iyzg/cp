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
    str garland, RGB = "", RBG = "", GBR = "", GRB = "", BRG = "", BGR = "";
    getline(cin, garland);
    getline(cin, garland);
    char a[3] = {'R', 'G', 'B'};
    char b[3] = {'R', 'B', 'G'};
    int rgbs = 0, rbgs = 0, gbrs = 0, grbs = 0, brgs = 0, bgrs = 0;
    F0R(i, n)
    {
        RGB += a[i % 3];
        RBG += b[i % 3];
        GBR += a[(i + 1) % 3];
        GRB += b[(i + 2) % 3];
        BRG += a[(i + 2) % 3];
        BGR += b[(i + 1) % 3];
        if (garland[i] != RGB[i])
            rgbs++;
        if (garland[i] != RBG[i])
            rbgs++;
        if (garland[i] != GBR[i])
            gbrs++;
        if (garland[i] != GRB[i])
            grbs++;
        if (garland[i] != BRG[i])
            brgs++;
        if (garland[i] != BGR[i])
            bgrs++;
    }
    pair<int, string> options[6];
    options[0] = mp(rgbs, RGB);
    options[1] = mp(rbgs, RBG);
    options[2] = mp(gbrs, GBR);
    options[3] = mp(grbs, GRB);
    options[4] = mp(brgs, BRG);
    options[5] = mp(bgrs, BGR);
    sort(options, options + 6);

    cout << options[0].f << "\n";
    cout << options[0].s;

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
