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
const int MX = 1000000;

int N, M, K, A, B, currComp = 0;
int museum[1000][1000] = {{ 0 }};
int comp[1000][1000] = {{ 0 }}, perim[MX] = { 0 };

int xd[4] = {1, 0, -1, 0};
int yd[4] = {0, 1, 0, -1};

void flood_fill(int a, int b) {
	comp[a][b] = currComp;
	F0R(i, 4)
	{
		int Y = a + yd[i], X = b + xd[i];
		if (museum[Y][X] && !comp[Y][X]) flood_fill(Y, X);
		else if (!museum[Y][X]) perim[currComp]++;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	F0R(i, N)
	{
		str line; cin >> line;
		F0R(j, M)
		{
			museum[i][j] = (line[j] == '.');
		}
	}
	
	F0R(i, N)
	{
		F0R(j, M)
		{
			if (museum[i][j] && !comp[i][j]) {
				currComp++;
				flood_fill(i, j);
			}
		}
	}
	
	F0R(i, K)
	{
		cin >> A >> B;
		cout << perim[comp[--A][--B]] << "\n";
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
