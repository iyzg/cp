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

ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int const MAX = 1000000001;
int main() {
    int n; cin >> n;
    ll c[3] = { 0 };
    ll a[n];
    F0R(i, n)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    ll s1 = a[0];
    ll s2 = a[1];
    ll s3 = a[2];
        
    F0R(i, n)
    {
        if (a[i] == s1) c[0]++;
        if (a[i] == s2) c[1]++;
        if (a[i] == s3) c[2]++;
    }

    ll ans = 1;
    if (s1 != s2 && s1 != s3 && s2 != s3)
    {
        ans = c[0] * c[1] * c[2];
    } else if (s1 == s2 && s2 == s3) {
        ans = (c[0] * (c[0] - 1) * (c[0] - 2)) / 6;
    } else if (s1 == s2 && s1 != s3) {
        ans = (c[0] * (c[0] - 1)) / 2 * c[2];
    } else {
        ans = (c[1] * (c[1] - 1)) / 2 * c[0];
    }

    cout << ans;

    return 0;
}
