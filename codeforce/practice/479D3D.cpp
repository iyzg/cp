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
    int n; cin >> n;
    ll a[n];
    set<ll> sa;
    bitset<100> head;
    head.set();

    F0R(i ,n) 
    {
        cin >> a[i];
        sa.insert(a[i]);
    }
    
    str seq = "";
    ll curr = 0;
    F0R(i, n)
    {
        if (a[i] % 2 == 0 && sa.find(a[i] / 2) != sa.end()) head[i] = 0;
        else if (sa.find(a[i] * 3) != sa.end()) head[i] = 0;

        if (head[i] == 1)
        {
            seq += to_string(a[i]) + " ";
            curr = a[i];
            sa.erase(curr);
            break;
        }
    }
    
    F0R(i, n - 1)
    {
        if (curr % 3 == 0 && sa.find(curr / 3) != sa.end())
        {
            seq += to_string(curr / 3) + " ";
            curr /= 3;
            sa.erase(curr);
        } else if (sa.find(curr * 2) != sa.end()) {
            seq += to_string(curr * 2) + " ";
            curr *= 2;
            sa.erase(curr);
        } else {
            break;
        }
    }
    
    cout << seq;


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
