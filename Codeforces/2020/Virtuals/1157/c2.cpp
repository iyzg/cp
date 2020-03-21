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

int N, curr = 0, lI, rI;
str moves = "";

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	lI = 0; rI = N - 1;
	vi a(N);
	F0R(i, N) cin >> a[i];
	while(lI <= rI && (a[lI] > curr || a[rI] > curr)) {
		if (a[lI] > curr && a[rI] > curr) {
			if (a[lI] < a[rI]) {
				curr = a[lI];
				moves += 'L';
				lI++;
			} else if (a[rI] < a[lI]) {
				curr = a[rI];
				moves += 'R';
				rI--;
			} else {
				int lA = 1, rA = 1;
				while (lI + lA < N && a[lI + lA] > a[lI + lA - 1]) lA++;
				while (rI - rA >= 0 && a[rI - rA] > a[rI - rA + 1]) rA++;
				if (lA > rA) {
					F0R(i, lA) moves += 'L';
				} else {
					F0R(i, rA) moves += 'R';
				}
			
				break;
			}
		} else if (a[lI] > curr) {
			curr = a[lI];
			moves += 'L';
			lI++;
			
		} else if (a[rI] > curr) {
			curr = a[rI];
			moves += 'R';
			rI--;
		} else break;
	}
	cout << sz(moves) << "\n" << moves;
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
