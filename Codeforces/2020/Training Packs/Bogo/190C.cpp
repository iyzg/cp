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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000001;

int N, seqi = -1;
// p : empty pair, i int, o taken pair
vector<pair<char, pair<int, int>>> q;
vs seq;
string input;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin.ignore(256, '\n');
	getline(cin, input);
	stringstream ss(input);
	
	while (ss >> input) {
		seqi++;
		seq.pb(input);
		q.pb(mp(input[0], mp(seqi, seqi)));
		if (sz(q) < 3) continue;
		if (q[q.size() - 3].f != 'p') continue;
		if (q[q.size() - 1].f == 'p' || q[q.size() - 2].f == 'p') continue;
		while (sz(q) >= 3 && q[q.size() - 3].f == 'p' && q[q.size() - 1].f != 'p' && q[q.size() - 2].f != 'p')
		{
			int start = q[sz(q) - 3].s.f;
			//cout << "Added < to " << q[sz(q) - 2].s.f << "\n";
			//cout << "Added > to " << q[sz(q) - 1].s.s << "\n";
			seq[q[sz(q) - 2].s.f] = '<' + seq[q[sz(q) - 2].s.f];
			seq[q[sz(q) - 1].s.f] = ',' + seq[q[sz(q) - 1].s.f];
			seq[q[sz(q) - 1].s.s] += '>';
			q.erase(q.end() - 3, q.end());
			q.pb(mp('o', mp(start, seqi)));
		}
	}
	
	if (sz(q) != 1 || (q[0].f != 'o' && q[0].f != 'i')) {
		cout << "Error occurred";
		return 0;
	}
	
	F0R(i, sz(seq)) 
	{
		cout << seq[i];
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
