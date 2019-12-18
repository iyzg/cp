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

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

str smaller(str a, str b)
{
    if (sz(a) > sz(b)) return b;
    else if (sz(a) < sz(b)) return a;
    else {
        F0R(i, sz(a))
        {
            if ((a[i] - '0') < (b[i] - '0'))
            {
                return a;
            } else if ((a[i] - '0') > (b[i] - '0')) {
                return b;
            }
        }
    }

    return a;
}

int main() {
    int l; cin >> l;
    str number; getline(cin, number);
    getline(cin, number);
    string ans = number;

    int ls = floor((ld)l / 2);
    int rs = ceil((ld)l / 2);
    while(ls > 0)
    {
        str left = number.substr(0, ls);
        str right = number.substr(ls);
        if (right[0] != '0')
        {
            str sum = doSum(left, right);
            ans = smaller(ans, sum);
            break;
        }

        --ls;
    }

    while (rs < l)
    {
        str left = number.substr(0, rs);
        str right = number.substr(rs);
        if (right[0] != '0')
        {
            str sum = doSum(left, right);
            ans = smaller(ans, sum);
            break;
        }

        ++rs;
    }

    cout << ans;

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
