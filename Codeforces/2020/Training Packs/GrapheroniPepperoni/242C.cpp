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
const int MX = 1e9;

set<pi> pool;
map<pi, int> m;

pi st, ed;
int N, R, A, B;

int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> st.f >> st.s >> ed.f >> ed.s;
	cin >> N;
	F0R(i, N)
	{
		cin >> R >> A >> B;
		FOR(j, A, B + 1) pool.insert(mp(R, j));		
	}
	
	trav(iter, pool) m[iter] = -1;
	queue<pi> q; while(!q.empty()) q.pop();
	q.push(st); m[st] = 0;
	while (!q.empty())
	{
		pi curr = q.front(); q.pop();
		F0R(i, 8)
		{
			int x = curr.f + dx[i], y = curr.s + dy[i];
			pi to = mp(x, y);
			if (m[to] == -1) {
				m[to] = m[curr] + 1; q.push(to);
			}
		}
	}
		
	cout << m[ed];
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
