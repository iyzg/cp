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
const int MX = 300005;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

int N, M, K, X, Y, W, printed = 0;
// Node, weight, edge index
vector<tuple<int, ll, int>> graph[MX];
vi p;
vl d;

void djikstra() {
	d.assign(N, INF);
	p.assign(N, -1);
	vector<bool> u(N, false);
	set<pair<ll, int>> q;
	
	d[0] = 0;
	q.insert(mp(0, 0));
	while (!q.empty())
	{
		int v = q.begin()->s;
		//cout << "ON NODE " << v << "\n";
		q.erase(q.begin());
		
		trav(child, graph[v])
		{
			int len = get<1>(child), nn = get<0>(child);
			if (nn == p[v] && printed < K && printed < N - 1) {
				cout << get<2>(child) << " ";
				printed++;
			}
			// If child is p[v] print
			if (d[v] + len < d[nn]) {
				q.erase(mp(d[nn], nn));
				d[nn] = d[v] + len;
				p[nn] = v;
				q.insert(mp(d[nn], nn));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	F0R(i, M)
	{
		cin >> X >> Y >> W;
		X--; Y--;
		graph[X].pb(make_tuple(Y, W, i + 1));
		graph[Y].pb(make_tuple(X, W, i + 1));
	}
	
	cout << min(K, N - 1) << "\n";
	djikstra();
	
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
