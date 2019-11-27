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

int const MAX = 1000000001;
int main() {
    int n; cin >> n;
    int c[3] = { 0 };
    ll a[n];
    ll s1 = MAX, s2 = MAX, s3 = MAX;
    F0R(i, n)
    {
        cin >> a[i];
        if (a[i] < s1)
            s1 = a[i];
        else if (a[i] < s2)
            s2 = a[i];
        else if (a[i] < s3)
            s3 = a[i];
    }
        
    F0R(i, n)
    {
        if (a[i] == s1)
            c[0]++;
        else if (a[i] == s2)
            c[1]++;
        else if (a[i] == s3)
            c[2]++;
    }
    
    cout << max(c[0], 1) * max(c[1], 1) * max(c[2], 1);

    return 0;
}
