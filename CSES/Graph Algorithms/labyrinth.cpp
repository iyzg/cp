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

int N, M, sx, sy, ex, ey;
string row;
pair<int, string> dp[1000][1000] = {{ {-1, ""} }};
int labyrinth[1000][1000] = {{ 0 }};
bool vis[1000][1000] = {{ false }}, found = false;
pair<int, string> ans = {-1, ""};

void travel(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	dp[y][x].f = 0;
	vis[y][x] = true;
	while (!q.empty())
	{
		x = q.front().f;
		y = q.front().s;
		if (x > 0 && !vis[y][x - 1] && labyrinth[y][x - 1]) 
		{
			q.push({x - 1, y});
			dp[y][x] = {
			travel(x - 1, y, steps + 1, dir + 'L');
		if (y > 0 && !vis[y - 1][x] && labyrinth[y - 1][x]) travel(x, y - 1, steps + 1, dir + 'U');
		if (x < M - 1 && !vis[y][x + 1] && labyrinth[y][x + 1]) travel(x + 1, y, steps + 1, dir + 'R');
		if (y < N - 1 && !vis[y + 1][x] && labyrinth[y + 1][x]) travel(x, y + 1, steps + 1, dir + 'D');
	
	//cout << "At " << y << ", " << x << "\n";
	if (labyrinth[y][x] == 2)
	{
		found = true;
		if (ans.f == -1)
		{
			ans.f = steps;
			ans.s = dir;
		} else if (steps < ans.f) {
			ans.f = steps;
			ans.s = dir;
		}
		return;
	}
	vis[y][x] = true;

}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	F0R(i, N)
	{
		cin >> row;
		F0R(j, M)
		{
			if (row[j] == '.') labyrinth[i][j] = 1;
			else if (row[j] == 'A') {
				sx = j;
				sy = i;
			} else if (row[j] == 'B') {
				ex = j;
				ey = i;
				labyrinth[i][j] = 2;
			}
		}
	}
	
	travel(sx, sy);
	
	if (!found)
	{
		cout << "NO";
	} else {
		cout << "YES\n" << ans.f << "\n" << ans.s;
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
