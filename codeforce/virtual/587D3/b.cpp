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

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}

int main() {
    int n, can, shot = 0, shots = 0; cin >> n;
    pi cans[n];
    str seq = "";
    F0R(i, n)
    {
        cin >> can;
        cans[i] = mp(can, i);
    }

    sort(cans, cans + n, sortinrev);
    
    F0R(i, n)
    {
        shots += cans[i].f * shot + 1;
        seq += to_string(cans[i].s + 1) + " ";
        shot++;
    }

    cout << shots << "\n";
    cout << seq;

    return 0;
}
