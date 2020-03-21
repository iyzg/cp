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

int N, M, R, C, X, Y;
int labyrinth[2000][2000];
pi movesLeft[2000][2000];
bool used[2000][2000];
int ans = 0;

int xd[4] = {1, 0, -1, 0};
int yd[4] = {0, 1, 0, -1};

bool valid(int r, int c) {
	return (labyrinth[r][c] && r >= 0 && r < N && c >= 0 && c < M);
}

// Only want to a node that was already checked if you have more left/right moves
void bfs(int r, int c, int left, int right) {
	queue<pi> q;
	q.push({r, c});
	movesLeft[r][c] = {left, right};
	while (!q.empty())
	{
		pi v = q.front();
		q.pop();
		if (!used[v.f][v.s]) {
			ans++;
			used[v.f][v.s] = true;
		}

		F0R(i, 4)
		{
			int A = v.f + yd[i], B = v.s + xd[i];
			if (valid(A, B) && (movesLeft[v.f][v.s].f - (xd[i] == -1) > movesLeft[A][B].f || movesLeft[v.f][v.s].s - (xd[i] == 1) > movesLeft[A][B].s)) {
				if ((i == 0 && movesLeft[v.f][v.s].s) || (i == 2 && movesLeft[v.f][v.s].f) || i % 2 == 1) {
					q.push({A, B});
					movesLeft[A][B] = {movesLeft[v.f][v.s].f - (xd[i] == -1), movesLeft[v.f][v.s].s - (xd[i] == 1)};
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> R >> C >> X >> Y;
	--R; --C;
	F0R(i, N)
	{
		str row; cin >> row;
		F0R(j, M) 
		{
			labyrinth[i][j] = (row[j] == '.');
			movesLeft[i][j] = {-1, -1};
			used[i][j] = false;
		}
	}
	
	bfs(R, C, X, Y);
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
