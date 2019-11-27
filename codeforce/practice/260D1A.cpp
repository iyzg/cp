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
    int n; 
    cin >> n;
    ll a[100005] = { 0 };
    ll dp[100005];
    
    int in;
    F0R(i, n) 
    {
        cin >> in;
        a[in]++;
    }

    dp[0] = 0;
    dp[1] = a[1];
    for (long long i = 2; i < 100005; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + (a[i] * i));
    }

    cout << dp[100004];
}
