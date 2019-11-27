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
    int n, m; cin >> n >> m;
    pair<string, string> words[m];
    bitset<3000> shorter;

    string a, b;
    F0R(i, m) {
        cin >> a >> b;
        words[i] = mp(a, b);

        if (sz(a) <= sz(b))
            shorter[i] = 0;
        else
            shorter[i] = 1;
    }

    string word, sentence = "";
    F0R(i, n)
    {
        cin >> word;
        F0R(j, m)
        {
            if (words[j].f == word || words[j].s == word)
            {
                if (shorter[j] == 0)
                    sentence += words[j].f;
                else 
                    sentence += words[j].s;

                sentence += " ";
            }
        }
    }
    
    cout << sentence;
    return 0;
}
