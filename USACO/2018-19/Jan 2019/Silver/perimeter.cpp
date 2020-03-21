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

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (s.size()) { setIn(s+".in"), setOut(s+".out"); }
    }
}

using namespace io;

int N, maxArea = -1, minPerim = -1, currComp;
char grid[1000][1000];
int comp[1000][1000], area[1000000], perim[1000000];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool valid(int a, int b) {
	return (a >= 0 && a < N && b >= 0 && b < N);
}

void flood_fill(int a, int b) {
	comp[a][b] = currComp; area[currComp]++;
	F0R(i, 4)
	{
		int A = a + dx[i], B = b + dy[i];
		if (valid(A, B) && grid[A][B] == '#' && !comp[A][B]) {
			flood_fill(A, B);
		} else if (!valid(A, B) || grid[A][B] == '.') {
			perim[currComp]++;
		}
	}
}

void solve() {
	F0R(i, 1000) F0R(j, 1000) comp[i][j] = 0;
	F0R(i, 1000000) area[i] = 0;
	F0R(i, 1000000) perim[i] = 0;
	currComp = 0;
	F0R(i, N)
	{
		F0R(j, N)
		{
			if (grid[i][j] == '#' && !comp[i][j]) {
				currComp++;
				flood_fill(i, j);
			}
		}
	}
	
	FOR(i, 1, currComp + 1)
	{
		if (area[i] > maxArea || (area[i] == maxArea && perim[i] < minPerim)) {
			maxArea = area[i];
			minPerim = perim[i];
		}
	}
}

int main() {
	setIO("perimeter");
	cin >> N;
	F0R(i, N)
	{
		str line; cin >> line;
		F0R(j, N)
		{
			grid[i][j] = line[j];
		}
	}
	
	solve();
	
	cout << maxArea << " " << minPerim;
}
