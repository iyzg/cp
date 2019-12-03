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
#define lb lower_bound
#define ub upper_bound

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    str in; getline(cin, in);
    set<int> a[26];
    F0R(i, sz(in))
    {
        a[in[i] - 97].insert(i);
    }

    int Q; cin >> Q;
    F0R(q, Q)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int pos; char c; cin >> pos >> c;
            --pos;
            a[in[pos] - 97].erase(pos);
            in[pos] = c;
            a[in[pos] - 97].insert(pos);
        } else {
            int l, r; cin >> l >> r;
            --l, --r;
            int cnt = 0;
            F0R(c, 26)
            {
                auto it = a[c].lb(l);
                if (it != a[c].end() && *it <= r) ++cnt;
            }
            cout << cnt << "\n";
        }
    }
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
