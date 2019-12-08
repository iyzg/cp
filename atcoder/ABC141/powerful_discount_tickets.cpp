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
    int N, M; cin >> N >> M;
    ld a[N];
    ll sum = 0;
    F0R(i, N) cin >> a[i];
    sort(a, a + N);
 
    R0F(i, N)
    {
        if (i == 0)
        {
            a[i] = a[i]/(pow(2, M));
            // Don't just use all tickets, check if previous one is worse on each ticket like usual
        } else {
            // While tickets are giving more benefit than moving on
            while (a[i] - a[i]/2 > a[i - 1] - a[i - 1]/2 && M > 0)
            {
                a[i] /= 2;
                if (a[i + 1] > a[i])
                {
                    i += 2;
                }
                M--;
            }
        }
    }
 
    F0R(i, N) sum += floor(a[i]);
    cout << sum;
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
