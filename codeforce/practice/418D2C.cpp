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

const int MAXN = 1502;
const int ALPHABET = 26;

int n;
char gar[MAXN];
int ans[ALPHABET][MAXN] = {{ 0 }};
int Q, m_i;
char c_i;

int main() {
    cin >> n; getchar();
    F0R(i, n) gar[i] = getchar() - 'a';

    F0R(c, ALPHABET)
    {
        F0R(i, n)
        {
            int replace_count = 0;
            FOR(j, i, n)
            {
                if (gar[j] != c) ++replace_count;
                ans[c][replace_count] = max(ans[c][replace_count], j - i + 1);
            }
        }
        FOR(i, 1, MAXN)
        {
            ans[c][i] = max(ans[c][i], ans[c][i - 1]);
        }
    }

    cin >> Q;
    F0R(q, Q)
    {
        cin >> m_i >> c_i;
        cout << ans[c_i - 'a'][m_i] << "\n";
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
