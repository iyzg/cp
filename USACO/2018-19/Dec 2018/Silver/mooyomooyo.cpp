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

int N, K, curr;
char grid[100][10];
int area[1000], comp[100][10];
bool done = false;

int xd[4] = {0,1,0,-1};
int yd[4] = {1,0,-1,0};

bool valid(int a, int b) {
	if (a < N && a >= 0 && b >= 0 && b < 10) return true;
	else return false;
}

void flood_fill(int a, int b) {
	comp[a][b] = curr; area[curr]++;
	F0R(i, 4)
	{
		int A = a + xd[i], B = b + yd[i];
		if (valid(A, B) && grid[a][b] == grid[A][B] && !comp[A][B]) {
			flood_fill(A, B);
		}
	}
}

void sim() {
	curr = 0;
	F0R(i, 1000) area[i] = 0;
	F0R(i, N) F0R(j, 10) comp[i][j] = 0;
	
	F0R(i, N)
	{
		F0R(j, 10)
		{
			if (grid[i][j] != '0' && !comp[i][j]) {
				curr++;
				flood_fill(i, j);
			}
		}
	}
	done = true;
	
	F0R(i, N)
	{
		F0R(j, 10)
		{
			if (area[comp[i][j]] >= K) {
				grid[i][j] = '0';
				done = false;
			}
		}
	}
	
	queue<char> q;
	F0R(i, 10)
	{
		R0F(j, N)
		{
			if (grid[j][i] != '0') {
				q.push(grid[j][i]);
				grid[j][i] = '0';
			}
		}
		
		R0F(j, N)
		{
			if (!q.empty() && grid[j][i] == '0') {
				grid[j][i] = q.front();
				q.pop();
			}
		}
	}
}

int main() {
	setIO("mooyomooyo");
	cin >> N >> K;
	F0R(i, N)
	{
		str line; cin >> line;
		F0R(j, 10)
		{	
			grid[i][j] = line[j];
		}
	}

	while(!done) sim();
	F0R(i, N)
	{
		F0R(j, 10)
		{
			cout << grid[i][j];
		}
		cout << "\n";
	}
	// Cout answer;
			
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
