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

int N;
bool possible = false, oneLine = false;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<pair<int, ld>> points(N);
	F0R(i, N)
	{
		points[i].f = i + 1;
		cin >> points[i].s;
	}
	
	FOR(i, 1, N)
	{
		ld slope = (points[i].s - points[0].s) / i;
		//cout << "Slope is " << slope << "\n";
		int secondStart = -1;
		FOR(j, 1, N)
		{
			if (j == i) continue;
			
			if (points[j].s != points[0].s + (slope * j)) {
				secondStart = j;
				break;
			}
		}
		
		if (secondStart == -1) {
			//cout << "ONE LINE";
			oneLine = true;
			possible = false;
			break;
		}
		
		//cout << "secondstart is " << secondStart << "\n";
		// Make sure second start is on another point
		FOR(j, 1, N)
		{
			possible = true;
			if (j != i && j != secondStart) {
				if ((points[j].s != points[0].s + (slope * j)) && (points[j].s != points[secondStart].s + (slope * (j - secondStart)))) {
					//cout << "Broke on " << j << " for " << i << "\n";
					possible = false;
					break;
				}
			}
		}
		
		if (possible) break;
	}
	
	if (!possible && !oneLine) {
		ld slope = (points[2].s - points[1].s) / (points[2].f - points[1].f);
		possible = true;
		FOR(i, 3, N) {
			if (points[i].s != points[1].s + (slope * (i - 1))) {
				possible = false; 
				break;
			}
		}
	}
			
	
	// Check all slopes from (1, y) to (N, y) and see if they're valid
	// final check is for if first point alone and slope in the rest 
	possible ? cout << "Yes" : cout << "No";
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
