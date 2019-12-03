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

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m; cin >> n >> m;
    ll a[n], t1[n], t2[n], l[n], r[n];
    F0R(i, n)
    {
        cin >> a[i];
        // Temp arrays to check for new minimums
        t1[i] = t2[i] = a[i];
    }

    vpi segs;
    vpi osegs;
    int in1, in2;
    F0R(i, m) 
    {
        cin >> in1 >> in2;
        --in1, --in2;
        segs.pb(mp(in1, in2));
        osegs.pb(mp(in1, in2));
    }

    sort(all(segs), sortbysec);

    int segi = 0;
    F0R(i, n)
    {
        l[i] = 1000001;
        if (i > 0) l[i] = l[i - 1];
        while (segi < sz(segs) && segs[segi].s < i)
        {
            //Apply seg and check if new minimum
            FOR(j, segs[segi].f, segs[segi].s + 1) --t1[j];
            segi++;
        }
        F0R(j, i) if (t1[j] < l[i]) l[i] = t1[j];
    }

    sort(all(segs), sortinrev);
    segi = 0;
    R0F(i, n)
    {
        r[i] = 1000001;
        if (i < n - 1) r[i] = r[i + 1];
        while (segi < sz(segs) && segs[segi].f > i)
        {
            FOR(j, segs[segi].f, segs[segi].s + 1) --t2[j];
            segi++;
        }
        FOR(j, i + 1, n) if (t2[j] < r[i]) r[i] = t2[j];
    }
    
    int currmax = -2000003;
    int oindex = 0;
    F0R(i, n)
    {
        if (a[i] - min(l[i], r[i]) > currmax)
        {
            currmax = a[i] - min(l[i], r[i]);
            oindex = i;
        }
    }

    cout << max(currmax, 0) << "\n";
    str chosensegs = "";
    int nchosen = 0;
    F0R(i, m)
    {
        if (oindex > osegs[i].s || oindex < osegs[i].f)
        {
            ++nchosen;
            chosensegs += to_string(i + 1) + " ";
        }
    }
    cout << nchosen << "\n";
    cout << chosensegs;

    return 0;
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
