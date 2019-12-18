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
    int Q; cin >> Q;
    F0R(q, Q)
    {
        int n; cin >> n;
        vl nums;
        set<ll> d;
        F0R(i, n)
        {
            ll in; cin >> in;
            nums.pb(in);
            d.insert(in);
        }

        sort(all(nums));
        ll number = nums[0] * nums[n - 1];
        int left = 0, right = n - 1;
        bool possible = true;
        for(; left <= right; ++left, --right)
        {
            if (nums[left] * nums[right] != number)
            {
                cout << -1 << "\n";
                possible = false;
                break;
            }
        }

        if (possible)
        {
            for(ll i = 2; i * i <= number; i++)
            {
                if (number % i == 0)
                {
                    if (d.find(number / i) == d.end() || d.find(i) == d.end())
                    {
                        cout << -1 << "\n";
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (possible) cout << number << "\n";

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
