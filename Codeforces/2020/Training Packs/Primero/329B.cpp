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
const int MX = 1000;

int R, C;
int forest[MX][MX], d[MX][MX];
bool visited[MX][MX];
int sr, sc, er, ec;
ll ans;
// dist -> number of breeders there
map<int, int> m;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool valid(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C && forest[r][c] > -1 && !visited[r][c]);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	F0R(i, MX) F0R(j, MX) forest[i][j] = -1;
	F0R(i, R)
	{
		str line; cin >> line;
		F0R(j, C)
		{
			if (line[j] == 'T') forest[i][j] = -1;
			else if (line[j] == 'S') {
				forest[i][j] = 10;
				sr = i;
				sc = j;
			} else if (line[j] == 'E') {
				forest[i][j] = 10;
				er = i;
				ec = j;
			} else {
				forest[i][j] = line[j] - '0';
			}
		}
	}
			
	// BFS from exit, and store distance away for each breeder then loop through to find ans
	queue<pi> q;
	q.push(mp(er, ec));
	visited[er][ec] = true;
	d[er][ec] = 0;
	while (!q.empty())
	{
		pi v = q.front();
		q.pop();
		if (forest[v.f][v.s] > 0 && forest[v.f][v.s] < 10) {
			m[d[v.f][v.s]] += forest[v.f][v.s];
		}
		F0R(i, 4)
		{
			int A = v.f + dy[i], B = v.s + dx[i];
			if (valid(A, B)) {
				d[A][B] = d[v.f][v.s] + 1;
				visited[A][B] = true;
				q.push(mp(A, B));
			}
		}
	}
	
	trav(i, m)
	{
		if (i.f > d[sr][sc]) break;
		
		ans += i.s;
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
